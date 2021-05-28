#include <stdio.h>
int main() {
    int arr[3][3] = { {10, 20, 30}, {100, 200, 300}, {100, 200, 300}};
    
    printf("arr의 주소값 : %p\n", &arr);
    
    for (int i = 0; i < 3; i++) {
        printf("arr[%d]의 주소값 : %p\n",i, &arr[i]);
        
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d]의 주소값 : %p / 값 :%d\n", i, j, &arr[i][j], arr[i][j]);
        }
    }
}


