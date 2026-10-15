#include <stdio.h>
#include <string.h>

#define MAX 200

// Address structure
struct Address {
    char village[50];
    int pincode;
};

// Member structure
struct Member {
    int id;
    char name[50];
    float share_capital;
    struct Address address;
};

int main() {
    int N;
    scanf("%d", &N);

    // Input validation
    if (N <= 0 || N > MAX) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Member members[N];
    float total_share = 0.0;

    // Read members
    for (int i = 0; i < N; i++) {
        scanf("%d %s %f %s %d",
              &members[i].id,
              members[i].name,
              &members[i].share_capital,
              members[i].address.village,
              &members[i].address.pincode);

        total_share += members[i].share_capital;
    }

    // Print ledger
    printf("MEMBER LEDGER\n");
    for (int i = 0; i < N; i++) {
        printf("%d %s %s %d %.2f\n",
               members[i].id,
               members[i].name,
               members[i].address.village,
               members[i].address.pincode,
               members[i].share_capital);
    }

    // Print total share capital
    printf("Total share capital (Rs): %.2f\n", total_share);

    // Find highest share capital holder
    int max_index = 0;
    for (int i = 1; i < N; i++) {
        if (members[i].share_capital > members[max_index].share_capital) {
            max_index = i;
        }
    }

    // Print highest holder details
    printf("Highest holder: %d %s %s %d %.2f\n",
           members[max_index].id,
           members[max_index].name,
           members[max_index].address.village,
           members[max_index].address.pincode,
           members[max_index].share_capital);

    return 0;
}
