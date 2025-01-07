#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j;
    char fname[10][10];
    int start[10], size[10], block[10][10];

    printf("Enter no. of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", fname[i]);
        printf("Enter starting block: ");
        scanf("%d", &start[i]);
        block[i][0] = start[i];
        printf("Enter no. of blocks: ");
        scanf("%d", &size[i]);
        printf("Enter block numbers: ");
        for (j = 1; j <= size[i]; j++) {
            scanf("%d", &block[i][j]);
        }
    }

    printf("File\tstart\tsize\tblock\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", fname[i], start[i], size[i]);
        for (j = 0; j < size[i]; j++) {
            printf("%d--->", block[i][j]);
        }
        printf("%d", block[i][j]);
        printf("\n");
    }

    getch();
    return 0;
}
/*
output:
Enter no. of files: 
2
Enter file name: abc
Enter starting block: 3
Enter no. of blocks: 3
Enter block numbers: 4 6 8
Enter file name: pqr
Enter starting block: 6
Enter no. of blocks: 6
Enter block numbers: 1 3 4 7 2 9
File    start   size    block
abc     3       3       3--->4--->6--->8
pqr     6       6       6--->1--->3--->4--->7--->2--->9

*/
