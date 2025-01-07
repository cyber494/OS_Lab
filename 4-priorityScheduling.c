#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, n, bt[10], p[10], compt[10], wt[10], tat[10], temp1, temp2;
    float sumwt = 0.0, sumtat = 0.0, avgwt, avgtat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of %d process\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);
    printf("Enter the priority of %d process\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i] > p[j]) {
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }

    compt[0] = bt[0];
    wt[0] = 0;
    for (i = 1; i < n; i++)
        compt[i] = bt[i] + compt[i - 1];
    for (i = 0; i < n; i++) {
        tat[i] = compt[i];
        wt[i] = tat[i] - bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }
    avgwt = sumwt / n;
    avgtat = sumtat / n;
    printf("\n");
    printf("Bt\tCt\tTat\tWt\n");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%2d\t%2d\t%2d\t%2d\n", bt[i], compt[i], tat[i], wt[i]);
    }
    printf("\n");
    printf("Avgwt = %.2f\tAvgtat = %.2f\n", avgwt, avgtat);
    printf("\n");
    getch();
}

/*
    output :

    Enter number of processes: 4
    Enter the burst time of 4 process
    6 5 3 5
    Enter the priority of 4 process
    4 2 6 3

    Bt      Ct      Tat     Wt

    5       5       5       0
    5      10      10       5
    6      16      16      10
    3      19      19      16

    Avgwt = 7.75    Avgtat = 12.50

*/