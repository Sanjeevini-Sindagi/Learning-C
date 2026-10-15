#include<stdio.h>
int main(){
int arr[10];
int *ptr = arr;
printf("Enter the elements in to the array");
for(int i=0;i<10;i++){
    scanf("%d",ptr+i);
}
for(int i=0;i<10;i++){
    printf("Element=%d",*(ptr+i));
}
return 0;

}