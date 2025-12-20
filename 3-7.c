#include <stdio.h>
    int N, i;
    float grandTotalCommission = 0.0;
struct SalesRecord {
    char name[50];
    float target;
    float actual;
    
};

int main() {
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    struct SalesRecord records[N];

    for (i = 0; i < N; i++) {
        float baseCommission;

        if (scanf("%f %f %s", &records[i].target, &records[i].actual, records[i].name) != 3) {
            break;
        }

        baseCommission = records[i].actual * 0.10;

        if (records[i].actual >= records[i].target * 1.20) {
            baseCommission += 200.0;
        } else if (records[i].actual >= records[i].target) {
            baseCommission += 50.0;
        } else if (records[i].actual < records[i].target * 0.90) {
            baseCommission -= 100.0;
        }

        grandTotalCommission += baseCommission;
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}