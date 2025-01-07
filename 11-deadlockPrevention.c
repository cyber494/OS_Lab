#include <stdio.h>
#include <conio.h>

int max[10][10], alloc[10][10], need[10][10], avail[10], i, j, p, r, finish[10] = {0}, flag = 0;

void fun();

int main() {
    printf("\n\nSIMULATION OF DEADLOCK PREVENTION");
    printf("Enter no. of processes, resources");
    scanf("%d%d", &p, &r);

    printf("Enter allocation matrix");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available matrix");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    fun();

    if (flag == 0) {
        if (finish[i] != 1) {
            printf("\n\n Failing: Mutual exclusion");
            for (j = 0; j < r; j++) {
                if (avail[j] < need[i][j])
                    avail[j] = need[i][j];
            }
            fun();
            printf("\n By allocating required resources to process %d deadlock is prevented ", i);
            printf("\n\n Lack of preemption");
            for (j = 0; j < r; j++) {
                if (avail[j] < need[i][j])
                    avail[j] = need[i][j];
                alloc[i][j] = 0;
            }
            fun();
            printf("\n\n Deadlock is prevented by allocating needed resources");
            printf("\n\n Failing: Hold and Wait condition");
            for (j = 0; j < r; j++) {
                if (avail[j] < need[i][j])
                    avail[j] = need[i][j];
            }
            fun();
            printf("\n Avoiding any one of the conditions, you can prevent deadlock");
        }
    }
    getch();
    return 0;
}

void fun() {
    while (1) {
        for (flag = 0, i = 0; i < p; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] <= avail[j])
                        continue;
                    else
                        break;
                }
                if (j == r) {
                    for (j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    flag = 1;
                    finish[i] = 1;
                }
            }
        }
        if (flag == 0)
            break;
    }
}
/*
SIMULATION OF DEADLOCK PREVENTION 
Enter no. of processes, resources 3, 2 
enter allocation matrix 
2 4 
5 3
4 5 
Enter max matrix 
4 3 
4 5 
6 1 
Enter available matrix2 5
 Failing : Mutual Exclusion by allocating required resources to process dead is prevented
 Lack of no preemption deadlock is prevented by allocating needed resources
 Failing : Hold and Wait condition

*/
