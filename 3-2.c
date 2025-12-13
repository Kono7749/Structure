#include <stdio.h>

struct Student
{
    char name[50];
    int studentid;
    float score;
};

int main(){
    int N;
    int i;

    if (scanf("%d", &N) != 1)
    {
        return 1;
    }
    
    struct Student students[N];
    for (i = 0; i < N; i++)
    {
        if (scanf("%d %f %s", &students[i].studentid, &students[i].score, students[i].name) != 3)
        {
            return 1;
        }
    
    for (i = 0; i < N; i++)
    {
        printf("ID: %d, Name: %s, Score: %2.f\n",students[i].studentid, students[i].name, students[i].score);
    }
    return 0;
    
}
}
