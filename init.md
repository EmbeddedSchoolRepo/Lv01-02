# 초기 설정

## 기본 프로그램 설정
```make
// 프로그램 설치 패키지 업데이트
sudo apt-get update
// 편집기 설치
sudo apt-get install vim
// git 설치
sudo apt-get install git
```

## 각자 자신의 저장소를 설정합니다.

https://github.com/EmbeddedSchoolRepo/Lv01-02 로 이동합니다.  
아래 절차를 따라서 작업을 진행해주세요.  

1. 홈페이지에서 fork를 눌러서 자신의 계정으로 내용을 가져옵니다.

```make
2. cd ~
3. mkdir proj
4. cd proj
5. mkdir es02
6. cd es02
7. git clone https://github.com/EmbeddedSchoolRepo/Lv01-02.git
8. ls
```

## 숙제 제출하는 방법(깃 활용)
```make
1. 현재 모두 위의 작업을 통해 저장소를 가지고 있을겁니다.
2. git config --list 를 통해 현재 저장소의 git name과 email을 확인합니다.
3. git config --global user.name "깃사용자명"
4. git config --global user.email "깃가입메일"
5. git config --list 를 통해 정상적으로 처리가 되었는지 확인합니다.
6. 그리고 여러분들의 이름에 해당하는 디렉토리로 이동해서 작업(숙제) 등을 진행합니다.
7. git status 를 입력하면 현재 상태를 알 수 있습니다.
8. 여기서 빨간색으로 나오는 정보들을 git add 형태로 추가하면 됩니다.
9. 이후 git commit "숙제 1회차(이름)" 형식으로 제출하면 되겠습니다.
10. commit 이후에 git push origin main 으로 여러분들 각자의 사본 저장소에 저장합니다.
11. 개인 사본 저장소에 가보면 Pull Request를 눌러서 PR 요청을 넣으면 완료입니다.
12. 이후 제가 승인하면 원본 저장소에 내용이 갱신됩니다.
```


