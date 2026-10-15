#include <stdio.h>

void A(int n);
void B(int n);

void A(int n) {
    if (n > 3) return;   // stop condition
    printf("A: %d\n", n);
    B(n + 1);            // A calls B
}

void B(int n) {
    if (n > 3) return;   // stop condition
    printf("B: %d\n", n);
    A(n + 1);            // B calls A
}

int main() {
    A(1);   // start with A
    return 0;
}
