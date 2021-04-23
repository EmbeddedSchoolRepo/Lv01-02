# Quiz

```
1. 피보나치 수열 문제를 배열을 활용해서 풀어보자!
   n항을 입력 받아 출력하도록 해보자!
```

```make
int num = 7;
int *pointer = &num;

----------------------------
|            7             | 0x1000 (num)
----------------------------
|          0x1000          | 0x0ff8 (pointer)
----------------------------
```

```make
---------------------------- rbp = 0x7fffffffdb80
|        .........         |
----------------------------
|      0x7fffffffdb6c      | rbp - 0x10 (0x7fffffffdb70)
----------------------------
|            7             | rbp - 0x14 (0x7fffffffdb6c)
----------------------------
```

```make
---------------------------- rbp = 0x7fffffffdb80
|        .........         |
----------------------------
|      0x7fffffffdb68      | rbp - 0x10 (0x7fffffffdb70) pp_num
----------------------------
|      0x7fffffffdb64      | rbp - 0x18 (0x7fffffffdb68) p_num
----------------------------
|            3             | rbp - 0x1c (0x7fffffffdb64) num
----------------------------
```