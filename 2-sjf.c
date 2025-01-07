#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
	int i, j, n, bt[10], compt[10], wt[10], tat[10], temp;
	float sumwt = 0.0, sumtat = 0.0, avgwt, avgtat;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter the burst time of %d process\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &bt[i]);
	}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (bt[i] > bt[j])
			{
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
			}
	compt[0] = bt[0];
	for (i = 1; i < n; i++)
		compt[i] = bt[i] + compt[i - 1];
	for (i = 0; i < n; i++)
	{
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
	for (i = 0; i < n; i++)
	{
		printf("%2d\t%2d\t%2d\t%2d\n", bt[i], compt[i], tat[i], wt[i]);
	}
	printf("\n");
	printf(" Avgwt = %.2f\tAvgtat = %.2f\n", avgwt, avgtat);
	printf("\n");
	getch();
}

/*
    output : 

    Enter number of processes: 4
    Enter the burst time of 4 process
    6 8 7 3

    Bt      Ct      Tat     Wt

    3       3       3       0
    6       9       9       3
    7      16      16       9
    8      24      24       16

    Avgwt = 7.00   Avgtat = 13.00
*/