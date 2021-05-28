#include <stdio.h>
void change_array(int(*arr)[3]) { //배열 포인터
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = 0; //arr의 값 0으로 변경
        }
    }
}

int main() {
    int arr[3][3] = { {10, 20, 30}, {100, 200, 300}, {100, 200, 300}};
	
    change_array(arr);

    //출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] : %d ", i, j, arr[i][j]);
        }
        printf("\n");
     }
}



