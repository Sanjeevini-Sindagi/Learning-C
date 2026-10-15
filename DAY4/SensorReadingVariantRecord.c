#include <stdio.h>
#include <string.h>

union Value {
    float temperature;
    char door;
    long pulses;
};

struct Reading {
    int sensorID;
    char kind;
    union Value value;
};

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0 || N > 1000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Reading readings[N];
    printf("SENSOR REPORT\n");

    for (int i = 0; i < N; i++) {
        int id;
        char kind;
        scanf("%d %c", &id, &kind);

        readings[i].sensorID = id;
        readings[i].kind = kind;

        switch (kind) {
            case 'T': {
                float temp;
                scanf("%f", &temp);
                readings[i].value.temperature = temp;
                printf("Sensor %d temperature %.2f C\n", id, temp);
                break;
            }
            case 'D': {
                char state;
                scanf(" %c", &state);
                readings[i].value.door = state;
                if (state == 'O')
                    printf("Sensor %d door OPEN\n", id);
                else if (state == 'C')
                    printf("Sensor %d door CLOSED\n", id);
                else {
                    printf("INVALID KIND\n");
                    return 0;
                }
                break;
            }
            case 'P': {
                long pulses;
                scanf("%ld", &pulses);
                readings[i].value.pulses = pulses;
                printf("Sensor %d pulses %ld\n", id, pulses);
                break;
            }
            default:
                printf("INVALID KIND\n");
                return 0;
        }
    }

    printf("sizeof(union Value): %zu\n", sizeof(union Value));
    printf("sizeof(Reading) with union: %zu\n", sizeof(struct Reading));
    printf("sizeof(Reading) with all fields: %zu\n", sizeof(int) + sizeof(char) + sizeof(float) + sizeof(char) + sizeof(long));
    printf("Bytes saved per record: %zu\n",
           (sizeof(int) + sizeof(char) + sizeof(float) + sizeof(char) + sizeof(long)) - sizeof(struct Reading));

    return 0;
}
