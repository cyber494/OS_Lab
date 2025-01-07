#include <stdio.h>
#include <conio.h>

void main() {
    int i, n, tq, full, time1 = 0;
    int bt[10], ct[10], time[10], wt[10], tat[10];
    char pn[10][10];
    float avgwt = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process name and burst time of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s %d", pn[i], &bt[i]);
        time[i] = bt[i];  
    }

    printf("Enter quantum: ");
    scanf("%d", &tq);

    full = n;  

    while (full) {
        for (i = 0; i < n; i++) {
            if (time[i] > 0) {
                if (time[i] > tq) {
                    time[i] -= tq;
                    time1 += tq;
                } else {
                    time1 += time[i];
                    time[i] = 0;
                    tat[i] = time1;  
                    full--;         
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        ct[i] = tat[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nPN\tBt\tCt\tTat\tWt\n");
    for (i = 0; i < n; i++) {
        printf("%2s\t%2d\t%2d\t%2d\t%2d\n", pn[i], bt[i], ct[i], tat[i], wt[i]);
        avgwt += wt[i];
    }

    avgwt = avgwt / n;
    printf("\nAverage waiting time = %.2f\n", avgwt);

    getch();
}


/*
    output :
    Enter number of processes: 5
    Enter process name and burst time of 5 processes:
    1 10
    2 5
    3 15
    4 3
    5 20
    Enter quantum: 5

    PN      Bt      Ct      Tat     Wt
    1      10      28      28      18
    2       5      10      10       5
    3      15      43      43      28
    4       3      18      18      15
    5      20      53      53      33

    Average waiting time = 19.80


*/