#include <stdio.h>
#include <conio.h>

int main() {
    int n, m[20], i, j, ib[20], b[20][20];

    printf("Enter no. of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter index block for file %d: ", i + 1);
        scanf("%d", &ib[i]);
        printf("Enter blocks occupied by file %d: ", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d: ", i + 1);
        for (j = 0; j < m[i]; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nFile\tIndex\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, ib[i], m[i]);
    }

    printf("Blocks occupied are:\n");
    for (i = 0; i < n; i++) {
        printf("File no %d: ", i + 1);
        for (j = 0; j < m[i]; j++) {
            printf("\t%d ---> %d\n", ib[i], b[i][j]);
        }
        printf("\n");
    }

    getch();
    return 0;
}

/*
output:
Enter no. of files: 2
Enter index block for file 1: 3
Enter blocks occupied by file 1: 5
Enter blocks of file 1: 5 7 2 9 3
Enter index block for file 2: 7
Enter blocks occupied by file 2: 6
Enter blocks of file 2: 2 7 3 9 4 6

File    Index   Length
1       3       5
2       7       6
Blocks occupied are:
File no 1:      3 ---> 5
        3 ---> 7
        3 ---> 2
        3 ---> 9
        3 ---> 3

File no 2:      7 ---> 2
        7 ---> 7
        7 ---> 3
        7 ---> 9
        7 ---> 4
        7 ---> 6

*/
