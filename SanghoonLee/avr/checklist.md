## Buzzer

```c
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0xff;

    while(1)
    {
        PORTC = 0x01;
        _delay_ms(100);
        PORTC = 0x00;
        _delay_ms(100);
    }

    return 0;
}
```

## LB1630 DC Motor

```c
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU           16000000UL
#include <util/delay.h>

#define IN1             PD0

#include <math.h>

void init_dc_motor(void)
{
    DDRB = 0xFF;
    DDRD = 0xFF;

    // Timer/Counter
    // WGM22, WGM21, WGM20 ==> Fast PWM, OCRA
    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    // COM2A1, COM2B1 ==>
    // Clear OC2B on compare match, set OC2B at BOTTOM,
    // (non-inverting mode).
    // 매칭이 되면 클리어
    TCCR2A |= (1 << COM2A1) | (1 << COM2B1);
    TCCR2B |= (1 << WGM22);
    // 64 분주 => 16000000 / 64 = 250000
    TCCR2B |= (1 << CS22);
}

ISR(PCINT0_vect)
{
    PORTB ^= 0x10;
}

int main(void)
{
    int count = 0;
    double speed, t;
    unsigned char velocity;

    init_dc_motor();

    // PB0 pin 초기화
    // PB0을 입력으로 설정
    DDRB &= ~(1 << DDB5);

    // Pull-Up 설정
    PORTB |= (1 << PORTB4);

    // PCIE0을 통해 PCMSK0 스캔
    PCICR |= (1 << PCIE0);
    // PCINT0을 상태 변경에 따른 인터럽트 트리거로 활용
    PCMSK0 |= (1 << PCINT5);

    // 인터럽트 활성화
    sei();

    while(1)
    {
        // count * PI / 180;
        // 1rad = 56.x degree
        // 360 degree = 2PI rad
        // 1 degree = 2 * PI / 360 rad
        //          = PI / 180 rad
        // 호도법(각도와 라디안의 관계)
        // 이유: math 라이브러리의 sin, cos, tan 등은 radian을 기반으로 동작하기 때문
        t = (double)count / 180.0 * 3.141592;
        // 255 * (0 ~ 360 degree)
        // sin의 특성: -1 ~ 1
        // -255 ~ 255
        speed = 255 * sin(t);
        // speed는 벡터(속도)
        velocity = (unsigned int)fabs(speed);
        // velocity는 스칼라(속력)

        // 양방향
        // OCA와 OCB를 통해 정방향, 역방향을 제어함
        if (speed > 0)
        {
            PORTD |= 0x08;
            PORTB &= ~0x08;
            OCR2A = 255 - velocity;
        }
        else
        {
            PORTD &= ~0x08;
            PORTB |= 0x08;
            OCR2A = velocity;
        }

        count++;
        // 속도의 변화율이 가속도이므로
        // 딜레이가 크면 가속도가 작고 작으면 가속도가 크다.
        // dv / dt
        // (나중 속도 - 이전 속도) / 시간(짧다고 가정) = 근사 가속도
        // 이와 같이 디지털로 미적분을 수행하는 기법을 수치해석이라고 한다.
        _delay_ms(20);
    }

    return 0;
}
```
