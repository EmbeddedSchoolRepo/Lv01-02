# Lv01-02
임베디드 스쿨 2기 - 레벨 1 

# 가장 우선 해야할 것

0. USB 용 시동디스크 만들기
1. 리눅스 설치(멀티 부팅 되게 설치하셔도 좋아요) - Version: Ubuntu 20.04 로 부탁드립니다.   
2. 멀티 부팅이 싫다면 그냥 전체를 리눅스로 설치해도 무방합니다.  
3. 요즘은 웹 브라우저용 공인 인증서가 있어서 리눅스로도 뱅킹이 가능합니다.    

## 설치시 발생하는 문제점들

1. LG 노트북의 경우 리눅스 설치가 매우 어려울 수 있습니다.  
2. 리눅스 노트북으로 추천은 Dell 혹은 Lenovo를 추천드립니다.  
3. 자금에 여유가 없으신 분들은 삼성 노트북도 나쁘지 않습니다.  
4. 현재 어쩔 수 없이 LG 노트북을 사용하셔야 하는 분의 경우엔 Virtual Box를 사용해서 Ubuntu 리눅스를 설치하면 될 것 같습니다.  
5. BIOS 설정시 발생할 수 있는 문제점으로 Secure Boot 등이 있는데 만약 USB 시동 디스크 인식이 잘 되지 않으면 카톡등을 통해 질문해주시면 감사하겠습니다.  

# 리눅스 설치 후 진행할 내용

## 업데이트 받기
```make
sudo apt-get update
sudo apt-get install vim
sudo apt-get install build-essential
sudo apt-get install git
```

## 학습 저장소 다운 받기
```make
mkdir proj
cd proj
git clone https://github.com/EmbeddedSchoolRepo/Lv01-02.git
cd Lv01-02
ls
```

## 현재 저장소의 상태를 확인하는 방법
```make
git status
```

## 저장소에 추가한 내용 혹은 변경 내역을 적용하는 방법
```make
git add (추가한내용)           필요하다면
git commit -am "작업한 내용에 대한 간략한 메시지를 기록합니다."
git push origin main
```

## 실제 수강생분들의 경우엔 fork를 해서 진행해야합니다.
```make
이 부분에 대해서는 첫날 수업시간에 리눅스가 설치된 노트북을 활용해서 같이 진행해보도록 하겠습니다.
```
