#include <stdio.h>
#include <stdbool.h>
bool jump_max(int arr[], int n) {
    bool a = true;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            a = false;
        }
    }
    return a;
}
int main(){
    int array[5];
    for(int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    if(jump_max(array, 5)) {
        printf("it can reach last index");
    } else {
        printf("it cannot reach last index");
    }
}