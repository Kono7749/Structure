#include <stdio.h>

struct Campaign {
    char name[50];
    float productPrice;
    int salesCount;
    float adSpend;
};

int main() {
    int N, i;

    if (scanf("%d", &N) != 1) {
        return 0;
    }

    struct Campaign campaigns[N];

    for (i = 0; i < N; i++) {
        float commissionRate;
        float totalRevenue;
        float totalCommission;
        float netProfitLoss;

        if (scanf("%s %f %d %f", campaigns[i].name, &campaigns[i].productPrice, 
                  &campaigns[i].salesCount, &campaigns[i].adSpend) != 4) {
            break;
        }

        if (campaigns[i].salesCount >= 20) {
            commissionRate = 0.20;
        } else if (campaigns[i].salesCount >= 10) {
            commissionRate = 0.15;
        } else {
            commissionRate = 0.10;
        }

        totalRevenue = (float)campaigns[i].salesCount * campaigns[i].productPrice;
        totalCommission = totalRevenue * commissionRate;
        netProfitLoss = totalCommission - campaigns[i].adSpend;

        printf("--- Campaign: %s ---\n", campaigns[i].name);
        printf("Sales: %d, Ad Spend: %.2f\n", campaigns[i].salesCount, campaigns[i].adSpend);
        printf("Rate Used: %.0f%%\n", commissionRate * 100);

        printf("Calculation: (%.2f * %.0f%%) - %.2f = %.2f\n", 
               totalRevenue, commissionRate * 100, campaigns[i].adSpend, netProfitLoss);
        
        printf("Net Result: %.2f\n", netProfitLoss);
    }

    return 0;
}