#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], ct[n], time[n], tat[n], wt[n];
    printf("Enter the Burst time of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        time[i] = bt[i];
    }

    int tq;
    printf("Enter quantum: ");
    scanf("%d", &tq);

    int full = n;
    int time1 = 0;
    while (full) {
        for (int i = 0; i < n; i++) {
            if (bt[i] >= tq) {
                bt[i] -= tq;
                time1 += tq;
            } else if (bt[i] > 0) {
                time1 += bt[i];
                bt[i] = 0;
            }

            if (bt[i] == 0 && time[i] != -1) {
                full--;
                tat[i] = time1;
                time[i] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ct[i] = tat[i];
        wt[i] = tat[i] - time[i];
    }

    float avgwt = 0;
    printf("PN\tBt\tCt\tTat\tWt\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\n", i + 1, time[i], ct[i], tat[i], wt[i]);
        avgwt += wt[i];
    }

    avgwt /= n;
    printf("\nAverage waiting time = %.2f\n", avgwt);

    return 0;
}
