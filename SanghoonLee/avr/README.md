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
잠시 보류
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




/etc/apt/sources.list <<<
