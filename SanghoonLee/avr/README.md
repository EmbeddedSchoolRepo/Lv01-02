# Ubuntu Linux 20.04에서 Arduino 기본 설정하기

먼저 아래 사이트에서 아두이노를 다운 받는다.  

https://www.arduino.cc/en/donate/  

Just Download를 눌러서 다운 받도록 한다.  

## 다운 받은 파일을 압축 해제한다.

1. 먼저 적정한 위치로 이동시킨다.  
2. 압축을 해제한다.  

tar xvf arduino-1.8.13-linux64.tar.xz  

## dfu-util을 설치해야 USB 통신이 정상적으로 동작할 수 있음

자동으로 설치하는 부분에 버그가 있어서 문제가 발생할 수 있기에 수동 설치를 진행해야 한다.  
먼저 이를 수행하기 위해 반드시 필요한 라이브러리가 있는데 아래와 같이 설치할 수 있다.  

sudo apt-get update  
sudo apt-get install libusb-1.0-0-dev  

## 소스 포지로 가서 dfu-util을 다운로드 받는다

https://sourceforge.net/projects/dfu-util/files/latest/download  

1. 적당한 위치로 이동시킨다.  
2. 압축을 해제한다.  

tar zxvf dfu-util-0.10.tar.gz  

## dfu-util 설치를 시작한다.

```
1. cd dfu-util
2. ./configure
3. make
4. make install
```

## Arduino 프로그램을 연다.

```
1. Tool -> Board -> Board Manager를 연다.
2. uno를 검색하고 Installed가 보이지 않는다면 Install을 클릭하여 설치한다.
```

## 구동 테스트를 하기 위해 아래 코드를 넣는다.

```c
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

## STK500 문제 해결이 필요함

```
FTDI 문제일 가능성이 있다.

1. https://ftdichip.com/drivers/d2xx-drivers/ 이동
2. x64 버전의 리눅스 전용을 다운 받는다.
3. 적정한 위치로 이동시키고 tar xvf libftd2xx-x86_64-1.4.22.tgz로 압축 해제
4. sudo cp release/build/lib* /usr/local/lib/
5. cd /usr/local/lib
6. ls libftd*
7. sudo ln -s libftd2xx.so.1.4.22 libftd2xx.so
8. sudo chmod 0755 libftd2xx.so.1.4.22
9. 
```

## Linux에서 AVR 코딩을 하기 위한 기본 설정

```
1. sudo apt-get update
2. sudo apt-get install codeblocks
```

## Linux 용 시리얼 프로그래머 설치

```
1. sudo add-apt-repository ppa:pmjdebruijn/avrdude-release
2. sudo apt-get update
3. sudo apt-get install libc6-dev-i386
4. sudo apt-get install binutils-avr gcc-avr avr-libc avrdude libc6-dev-i386
```

## 설치 확인

```
1. codeblocks
2. avrdude
```

## 기본 예제 돌려보기

```
1. 적당한 위치로 이동한다.
2. mkdir -p 적당한위치/proj/avr
3. Codeblock에서 File -> New -> Project -> AVR Project
4. Next
5. Project title: blink
   Folder to create project in: 위치(위에서 잡은 위치로 지정하는 것이 좋음)
   project filename: blink.cbp
   Resulting filename: ~~~
   Next
6. Uncheck: Create "Debug" configuration
   Next
7. Please choose a processor for this project: atmega328p
   Uncheck: Create Fuse, Lock, Signature ~~~
8. Finish
```

## AVR 코드 작성해보기

```
#include <avr/io.h>

#define F_CPU           16000000L
#include <util/delay.h>

int main(void)
{
    DDRB = 0x20;

    while(1)
    {
        PORTB = 0x00;
        _delay_ms(500);
        PORTB = 0x20;
        _delay_ms(500);
    }

    return 0;
}
```

톱니 버튼을 누르면 build가 진행된다.  
특별한 문제가 없다면 error가 0으로 나온다.  
이제 실제 프로젝트 디렉토리로 이동해보자!  

cd bin/Release  
ls  

여기에 *.hex 파일이 있는지 확인하도록 한다.  

## Build 완료된 AVR 코드 다운로드하기

```
1. 보드의 전원을 내린다.
2. 먼저 구동시킬 회로도를 구성한다.
3. 회로 구성이 완료되었다면 MKII ISP와 전원을 연결한다.
4. ~~~/bin/Release 디렉토리에 있는지 위치를 확인하고
   sudo avrdude -c avrisp2 -p m328p -U flash:w:blink_test.hex
5. 
```



/etc/apt/sources.list <<<
