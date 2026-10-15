#include <stdio.h>

// Function to calculate minimum eating speed
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = 0;
    for (int i = 0; i < pilesSize; i++)
        if (piles[i] > right) right = piles[i];

    while (left < right) {
        int mid = (left + right) / 2;
        int hours = 0;
        for (int i = 0; i < pilesSize; i++)
            hours += (piles[i] + mid - 1) / mid; // ceil division

        if (hours <= h)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int pilesSize, h;

    // Input number of piles
    printf("Enter number of piles: ");
    scanf("%d", &pilesSize);

    int piles[pilesSize];

    // Input pile values
    printf("Enter the number of bananas in each pile:\n");
    for (int i = 0; i < pilesSize; i++) {
        scanf("%d", &piles[i]);
    }

    // Input hours
    printf("Enter total hours available: ");
    scanf("%d", &h);

    // Calculate result
    int result = minEatingSpeed(piles, pilesSize, h);
    printf("Minimum eating speed: %d\n", result);

    return 0;
}
