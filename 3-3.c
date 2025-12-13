#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N;
    float totalScore = 0.0;
    float averageScore = 0.0;

    if (scanf("%d", &N) != 1) {

        return 1;
    }

    struct Student students[N];

    if (N == 0) {
        printf("Average Score: %.2f\n", 0.00);
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &students[i].studentId) != 1) return 1;
        if (scanf("%f", &students[i].score) != 1) return 1;
        if (scanf("%s", students[i].name) != 1) return 1;

        totalScore += students[i].score;
    }

    if (N > 0) {
        averageScore = totalScore / N;
    } else {
        averageScore = 0.0;
    }

    printf("Average Score: %.2f\n", averageScore);

    return 0;
}