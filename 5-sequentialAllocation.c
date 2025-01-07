#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];

    printf("Enter no.of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file%d: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the starting block of file%d: ", i + 1);
        scanf("%d", &sb[i]);
        t[i] = sb[i];
        for (j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }

    printf("Filename\tStart block\tLength\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);

    printf("Blocks occupied are:\n");
    for (i = 0; i < n; i++) {
        printf("File no %d: ", i + 1);
        for (j = 0; j < b[i]; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    getch();
    return 0;
}

/*
    output:
    Enter no.of files: 2
    Enter no. of blocks occupied by file1: 14
    Enter the starting block of file1: 2
    Enter no. of blocks occupied by file2: 10
    Enter the starting block of file2: 5
    Filename        Start block     Length
    1               2               14
    2               5               10
    Blocks occupied are:
    File no 1: 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    File no 2: 5 6 7 8 9 10 11 12 13 14

*/

