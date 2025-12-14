#include <stdio.h>

// 1. ประกาศโครงสร้าง (struct) ชื่อ Transaction
struct Transaction {
    char description[50]; // คำอธิบายธุรกรรม
    float amount;         // จำนวนเงิน (บวกสำหรับรายรับ, ลบสำหรับรายจ่าย)
};

int main() {
    int N, i;
    float totalIncome = 0.0;
    float totalExpense = 0.0;
    float netBalance = 0.0;

    if (scanf("%d", &N) != 1 || N < 0) {
        fprintf(stderr, "Invalid input for N.\n");
        return 1;
    }

    struct Transaction transactions[N];

    
    for (i = 0; i < N; i++) {
        if (scanf("%f %s", &transactions[i].amount, transactions[i].description) != 2) {
            return 1;
        }

        // 4. การจำแนก/สะสมยอด
        if (transactions[i].amount >= 0.0) {
            // ถือเป็น รายรับ (Income)
            totalIncome += transactions[i].amount;
        } else {
            totalExpense += -transactions[i].amount;
        }
    }
    netBalance = totalIncome - totalExpense;

    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", netBalance);

    return 0;
}