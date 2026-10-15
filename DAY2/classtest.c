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
    printf("The rotated matrix is: \n");
    for(int j=0;j<n;j++){
        for(int i=m-1;i>=0;i--){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}