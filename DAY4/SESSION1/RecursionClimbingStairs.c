#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2)
        return n;  // base cases
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int n;
    printf("Enter number of steps: ");
    scanf("%d", &n);
    printf("Number of ways to climb: %d\n", climbStairs(n));
    return 0;
}
