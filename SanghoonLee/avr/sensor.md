```c
/*
 */

#define F_CPU      16000000UL

#include <util/delay.h>
#include <avr/interrupt.h>

#include <avr/io.h>

static volatile uint32_t first_reading = 0;
static volatile uint32_t second_reading = 0;
static volatile uint32_t duty_cycle = 0;

void uart_init(void)
{
    UCSR0A |= _BV(U2X0);

    UBRR0H = 0x00;
    UBRR0L = 207;

    UCSR0C |= 0x06;

    UCSR0B |= _BV(RXEN0);
    UCSR0B |= _BV(TXEN0);
}

unsigned char uart_receive (void)
{
    while (!(UCSR0A & (1 << RXC0)))
    {
        ;
    }

    return UDR0;
}

void uart_transmit (unsigned char data)
{
    while (!(UCSR0A & (1 << UDRE0)))
    {
        ;
    }

    UDR0 = data;
}

void uart_print_string (char *str)
{
    int i;

    for (i = 0; str[i]; i++)
    {
        uart_transmit(str[i]);
    }
}

void uart_print_8bit_num (uint8_t no)
{
    char num_string[4] = "0";
    int i, index = 0;

    if (no > 0)
    {
        for (i = 0; no != 0; i++)
        {
            num_string[i] = no % 10 + '0';
            no = no / 10;
        }

        num_string[i] = '\0';
        index = i - 1;
    }

    for (i = index; i >= 0; i--)
    {
        uart_transmit(num_string[i]);
    }
}

void HCSR04_init (void)
{
    // 기존 인터럽트들을 클리어 시킴
    cli();
    // PD6을 출력 핀으로 설정함
    DDRD |= (1 << DDD6);
    // prescaler = 8
    TCCR0A = (1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);
    TCCR0B = (1 << CS01);
    // 10us trigger pulse, 118us off-time (total 128us)
    OCR0A = 235;
    /* 결국 PD6이 trigger로 설정됨 */

    // PB0을 입력 핀으로 설정
    DDRB &= ~(1 << DDB0);
    // 잡음 차단 + 엣지 검출, prescaler = 8, 입력 캡쳐
    TCCR1B = (1 << ICNC1) | (1 << ICES1) | (1 << CS11);
    // 인터럽트 활성화
    sei();

    // Timer 1을 입력 캡쳐 인터럽트로 활용
    TIMSK1 |= (1 << ICIE1);
    /* PB0이 echo로 설정됨 */
}

uint32_t get_distance (void)
{
    static uint32_t echo_pulse_us;
    static uint32_t distance_cm;

    // 32768us = 65536 clock 틱
    // 이것은 결국 Timer 1에 prescaler = 8
    echo_pulse_us = (float) duty_cycle * 32768 / 65536;
    distance_cm = echo_pulse_us * 0.034 / 2;
    /* 0.034인 이유는 음속의 디폴트 값이 340 m/s에 해당하기 때문: 이 속도가 마하 1 */
    /* dx / dt = v */
    /* 첫 번째 샘플: 50 cm
       두 번째 샘플: 70 cm
       샘플링 주파수 = 100 hz
       속도 = (70 - 50) * 100 = 2000cm/s = 20m/s
       첫 번째 샘플: 70 cm
       두 번째 샘플: 50 cm
       속도 = (50 - 70) * 100 = -2000cm/s = -20m/s */
    return distance_cm;
}

ISR (TIMER1_CAPT_vect)
{
    if ((TCCR1B & (1 << ICES1)) == (1 << ICES1))
    {
        first_reading = ICR1;
    }
    else
    {
        second_reading = ICR1;
    }

    if (first_reading != 0 && second_reading != 0)
    {
        duty_cycle = second_reading - first_reading;
        first_reading = 0;
        second_reading = 0;
    }

    // 엣지 검출 비트 토글
    TCCR1B ^= (1 << ICES1);
    // 캡쳐 플래그 클리어
    TIFR1 = (1 << ICF1);
}

int main(void)
{
    uint32_t distance;

    uart_init();
    HCSR04_init();

    DDRC |= 0x01;
    DDRC &= ~0xFD;

    while(1)
    {
        distance = get_distance();

        uart_print_string("distance(cm) = ");
        uart_print_8bit_num(distance);
        uart_transmit('\n');

        _delay_ms(1000);
    }

    return 0;
}
```
