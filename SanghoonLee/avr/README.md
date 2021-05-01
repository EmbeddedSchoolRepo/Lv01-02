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

