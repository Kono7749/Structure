#include <stdio.h>

int main() {
    int N_CALCULATIONS, i;
    int attkLvl, oppLvl, oppArmor;
    float baseAttack, damageReduction;
    const float WORTH_THRESHOLD = 150.0;

    if (scanf("%d", &N_CALCULATIONS) != 1) {
        return 1;
    }

    float netDamages[N_CALCULATIONS];
    float deficits[N_CALCULATIONS];
    int isSuccess[N_CALCULATIONS];

    for (i = 0; i < N_CALCULATIONS; i++) {
        if (scanf("%d %d %d", &attkLvl, &oppLvl, &oppArmor) != 3) {
            break;
        }

        baseAttack = attkLvl * 10.0;

        if (oppArmor < 50) {
            damageReduction = 0.20;
        } else {
            damageReduction = 0.40;
        }

        netDamages[i] = baseAttack * (1.0 - damageReduction);

        if (netDamages[i] >= WORTH_THRESHOLD) {
            isSuccess[i] = 1;
        } else {
            isSuccess[i] = 0;
            deficits[i] = WORTH_THRESHOLD - netDamages[i];
        }
    }

    for (i = 0; i < N_CALCULATIONS; i++) {
        if (isSuccess[i] == 1) {
            printf("SUCCESS! Net Damage: %.2f\n", netDamages[i]);
        } else {
            printf("FAIL. Deficit: %.2f\n", deficits[i]);
        }
    }

    return 0;
}
