#include<stdio.h>
int main(){
    int m , n;
    printf("Enter the rows and columns of the matrix: ");
    scanf("%d %d",&m,&n);
    int matrix[m][n];
    printf("Enter the elements of the matrix: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("The frequency of each digit is: \n");
    int frequency[10] = {0}; // Array to store frequency of digits 0-9
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int num = matrix[i][j];
            while(num > 0){
                int digit = num % 10;
                frequency[digit]++;
                num /= 10;
            }
        }
    }
    for(int i=0;i<10;i++){
        if(frequency[i] > 0){
            printf("Digit %d: %d times\n", i, frequency[i]);
        }
    }
    return 0;

}