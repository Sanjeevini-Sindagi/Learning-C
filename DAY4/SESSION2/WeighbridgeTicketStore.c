#include <stdio.h>
#include <stdlib.h>

// Ticket structure
struct Ticket {
    int ticket_no;
    char vehicle_reg[20];
    float gross;
    float tare;
};

// Helper function 1: compute net weight
float net_weight(struct Ticket *t) {
    return t->gross - t->tare;
}

// Helper function 2: print ticket details
void print_ticket(struct Ticket *t) {
    printf("%d %s gross %.2f tare %.2f net %.2f\n",
           t->ticket_no,
           t->vehicle_reg,
           t->gross,
           t->tare,
           net_weight(t));
}

int main() {
    int N;
    scanf("%d", &N);

    // Input validation
    if (N <= 0 || N > 100000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    // Dynamic allocation
    struct Ticket *tickets = (struct Ticket *)malloc(N * sizeof(struct Ticket));
    if (tickets == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    float total_net = 0.0;
    int max_index = 0;

    // Read tickets
    for (int i = 0; i < N; i++) {
        scanf("%d %s %f %f",
              &tickets[i].ticket_no,
              tickets[i].vehicle_reg,
              &tickets[i].gross,
              &tickets[i].tare);

        float net = net_weight(&tickets[i]);
        total_net += net;

        if (net > net_weight(&tickets[max_index])) {
            max_index = i;
        }
    }

    // Print day book
    printf("WEIGHBRIDGE DAY BOOK\n");
    for (int i = 0; i < N; i++) {
        print_ticket(&tickets[i]);
    }

    // Totals
    printf("Tickets: %d\n", N);
    printf("Total net weight (kg): %.2f\n", total_net);

    // Heaviest load
    printf("Heaviest net load: ticket %d %s %.2f\n",
           tickets[max_index].ticket_no,
           tickets[max_index].vehicle_reg,
           net_weight(&tickets[max_index]));

    // Free memory
    free(tickets);
    return 0;
}
