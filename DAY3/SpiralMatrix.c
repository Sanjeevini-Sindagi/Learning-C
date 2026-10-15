#include <stdio.h>

int main() {
    int r, c;
scanf("%d %d", &r, &c);

int arr[r][c];
int *ptr = &arr[0][0];


for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        scanf("%d", ptr + (i * c) + j);
    }
}

    int top = 0, bottom = 2;
    int left = 0, right = 2;

    while (top <= bottom && left <= right) {

        // Left to right
        for (int j = left; j <= right; j++) {
            printf("%d ", arr[top][j]);
        }
        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++) {
            printf("%d ", arr[i][right]);
        }
        right--;

        // Right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d ", arr[bottom][j]);
            }
            bottom--;
        }

        // Bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }

    return 0;
}