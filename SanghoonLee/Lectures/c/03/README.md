# 비트 연산자

## AND

C 프로그램 내에서는 & 로 사용하고 있다.  
관계 연산자에서는 && 로 사용된다.  
동작 방식은 서로 같은 자리수의 비트가 1(참)인지에 따라 결정됨  

진리표  

   1  0  1  0  0  (20)  
&  0  1  1  1  0  (14)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
   0  0  1  0  0  (4)  

## OR

C 프로그램 내에서는 | 로 사용한다.  
관계 연산자에서는 || 로 사용된다.  
동작 방식은 같은 자리수의 비트에 하나라도 1(참)이 있다면 참이 된다.  

진리표  

   1  0  1  0  0  (20)  
|  0  1  1  1  0  (14)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
   1  1  1  1  0  (30)  

## NOT

C 프로그램 내에서는 ~ 로 사용한다.  
관계 연산자는 ! 로 사용된다.  
동작 방식은 무조건 비트를 반전시킨다.  

진리표  

~           1  0  1  0  0  (20)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
111111...   0  1  0  1  1  

기본적으로 변수들은 레지스터에 할당됩니다.  
그런데 메모리 계층구조상 레지스터의 용량은 ? 작다.  
작기 때문에 많은 분량을 수용할 수가 없다.  
그러므로 상대적으로 용량이 큰 메모리(DRAM)을 사용하게 된다.  
(하지만 실질적인 연산 체계는 레지스터가 담당한다 - ALU)  

레지스터에 값이 써져 있지 않다면 ?  
플로팅 상태라고 하는데 이런 상태를 원치 않으니  
내부적으로 회로에 값을 설정하지 않으면 0 으로 셋팅되게 되어 있다.  

레지스터 비트수는 ? 64 비트  
그러므로 int라 가정했을때  
실질적으로 위의 5비트 앞에 27 비트의 0이 배치되어 있는 것!  
결국 NOT 연산은 비트 반전이 발생하므로 상위에 있는 나머지 비트들도 살펴봐야 한다.  

## XOR

C 프로그램 내부에서는 ^ 로 표시한다.  
안타깝게도 관계 연산자는 없다.  

동작이 특이한데 비트가 서로 교차될 경우에만 1(참)이 되며  
비트가 서로 교차하지 않는다면 0(거짓)이 된다.  
이 특성 때문에 암호화 과정에서 많이 사용하게 된다.  

진리표  

   1  0  1  0  0  (20)  
^  0  1  1  1  0  (14)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
   1  1  0  1  0  (26)  

## 우리가 집중해서 살펴볼 부분

1. not의 동작  

0의 보수, 1의 보수, 2의 보수 ...  보기 싫어요.  

+1 + (-1) = 0  

보통 숫자는 부호 비트가 최상단에 배치되어 있고 하위로 숫자를 표현하게 되어 있음  
결국 부호비트가 1이면 음수가 되고 0이면 양수가 됨  
그렇다면 -1은 1000 0001(8비트 가정)이라 할 수 있는것인가 ?  

  0000 0001 (+1)  
+ 1000 0001 (-1)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1000 0010 ???? 0000 0000 ???  

결국 0을 만족하지 못하므로 이것을 -1이라 할 수 없다.  

 11111 111  올림 발생  
  0000 0001 (+1)  
+ 1111 1111 (-1)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  0000 0000 (0)  

하드웨어 레지스터에 보면 EFLAGS(Intel), CPSR | SPSR (ARM)에 캐리비트가 셋됨  

어떤 수를 음수로 표현하기 위한 규칙을 찾아야 한다.  

1-1. 뒤쪽에서 가장 먼저 나오는 1을 찾는다.  
1-2. 맨 뒤에서 1까지의 숫자들은 그대로 유지한다.  
1-3. 1 이후의 숫자들은 전부 반전을 시킨다.  

 11111 11  
  0000 1010 (+10)  
+ 1111 0110 (-10)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  0000 0000 (0)  

 11111 1  
  0001 0100 (+20)  
+ 1110 1100 (-20)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  0000 0000 (0)  

돌발퀴즈: 숫자 37을 지금 방식을 통해 -37로 만들어보자!  

 11111 111  
  0010 0101 (+37)  
+ 1101 1011 (-37)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  0000 0000 (0)  

  1100 1001 (-X) = -55  
  0011 0111 (+X) = 1 + 2 + 4 + 16 + 32 = 55  

NOT을 분석해보자!  

~10

~ 0000 1010 (+10)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1111 0101 (-X)  

  1111 0101 (-X) = -11  
  0000 1011 (+X) = 1 + 2 + 8 = 11  

돌발퀴즈: ~39에 위의 방식을 적용하는 연습을 해보자!  

~ 0010 0111 (+39)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1101 1000 (-X)  

  1101 1000 (-X) = -40  
  0010 1000 (+X) = 32 + 8 = 40  

2. xor의 활용  

A = 65  
a = 97  

  1 0 0 0 0 0 1 (65)  
^ 0 1 0 0 0 0 0 (32)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1 1 0 0 0 0 1 (97)  

  1 1 0 0 0 0 1 (97)  
^ 0 1 0 0 0 0 0 (32)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1 0 0 0 0 0 1 (65)  

돌발퀴즈: 70에 xor 0x20(32)를  
적용하는 동작을 직접 그려보도록 합니다.  

  1 0 0 0 1 1 0 (70)  
^ 0 1 0 0 0 0 0 (32)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1 1 0 0 1 1 0 (102)  

  1 1 0 0 1 1 0 (102)  
^ 0 1 0 0 0 0 0 (32)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  1 0 0 0 1 1 0 (70)  

3. and not이란  

사용처는 2의 n승 단위 정렬을 하고자 하는 경우에 매우 유용하다.  
보통 리눅스 커널의 페이지 프레임이 4KB(4096) = 2^12  
페이지 크기를 정렬하는 목적으로 만이 사용한다.  

1000 & ~(2^n - 1)  

23 = 16 + 4 + 2 + 1  

11 1110 1000 (1000) = 8 + 32 + 64 + 128 + 256 + 512 = ? 1000  

1111 (15) = 10000 - 1 = 16 - 1  
11111 (31) = 100000 - 1 = 32 - 1  
11011 (27) = 31 - 4 = 27  

100 0000 0000 (1024)  
 11 1111 1111 (1023)  
       1 0111 (23)  
 11 1110 1000 (1000)  

(2^n - 1) => 11111...111 (2진수)  
16 => 10000 - 1 = 1111 (2진수)  
32 => 100000 - 1 = 11111 (2진수)  
64 => 1000000 - 1 = 111111 (2진수)  

결국 위의 흐름을 따르면 ~(2^n - 1) => 11111...111000..000의 형태를 가지게 된다.  

  11 1110 1000 (1000)  
& 11 1100 0000 ~(2^n - 1)  
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
  11 1100 0000 = 64 + 128 + 256 + 512 = 320 + 640 = 960  

이와 같은 이유 때문에 2^n 단위로 숫자를 정렬할 수 있게 된다.  



# 함수

## 프로토타입
```make
리턴 타입: 어떠한 데이터 타입을 return 할 것인지
인자 타입: 어떠한 데이터 타입을 입력으로 수용할 것인지  
함수 이름: 호출할 이름
```

돌발퀴즈: float 타입의 변수 3개를 서로 더하도록 함수를 만들어보자!  

## gdb 디버깅 방법

1. 먼저 프로그램에 -g 옵션을 붙여서 컴파일 한다.  
2. gdb 실행파일명  
3. b main  
4. r  
5. disas  

여기서 어셈블리어를 볼 수 있다.  
다음 시간에는 이 내용을 기반으로 C언어 설계의 전반을 살펴보도록 한다.  

l: C 레벨로 현재 코드를 볼 수 있음  
n: 명령어 한 줄 실행(함수 호출 건너뛰기)  
s: 명령어 한 줄 실행(함수 호출 타고 들어감)  
ni: 어셈블리 명령어 한 줄을 실행함(함수 호출 건너뜀)  
si: 어셈블리 명령어 한 줄 실행(함수 호출 타고 들어감)  
disas: 어셈블리 코드를 볼 수 있음  