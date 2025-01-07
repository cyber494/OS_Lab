#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    int i, j, n, bt[10], compt[10], at[10], wt[10], tat[10];
    float sumwt = 0.0, sumtat = 0.0, avgwt, avgtat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of %d process\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time of %d process\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    compt[0] = bt[0] - at[0];
    for (i = 1; i < n; i++) {
        compt[i] = bt[i] + compt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = compt[i] - at[i];
        wt[i] = tat[i] - bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }

    avgwt = sumwt / n;
    avgtat = sumtat / n;

    printf("\n");
    printf("PN\tBt\tCt\tTat\tWt\n");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%2d\t%2d\t%2d\t%2d\n", i, bt[i], compt[i], tat[i], wt[i]);
    }

    printf("\n");
    printf("Avgwt = %.2f\tAvgtat = %.2f\n", avgwt, avgtat);
    printf("\n");

    getch();
}


/*
    output :
    Enter number of processes: 5
    Enter the burst time of 5 process
    3 6 4 5 2
    Enter the arrival time of 5 process
    0 2 4 6 8

    PN      Bt      Ct      Tat     Wt

    0        3       3       3       0
    1        6       9       7       1
    2        4      13       9       5
    3        5      18      12       7
    4        2      20      12      10

    Avgwt = 4.60    Avgtat = 8.60

*/