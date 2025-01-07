//Bankers Avoidance
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of Resources: ");
    scanf("%d", &m);

    int alloc[n][m], maxi[n][m], needs[n][m], avail[m];
    for (int i = 0; i < n; i++) {
        printf("Enter the p%d Allocation Resources one by one: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the p%d Maximum Resources one by one: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &maxi[i][j]);
            needs[i][j] = maxi[i][j] - alloc[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Needs of p%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", needs[i][j]);
        }
        printf("\n");
    }

    printf("Enter Initial Available resources: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    int final[n], size = 0;
    for (int y = 0; y < n; y++) {
        for (int i = 0; i < n; i++) {
            int execute = 0;
            for (int j = 0; j < m; j++) {
                if (needs[i][j] <= avail[j]) {
                    execute++;
                }
            }
            if (execute == m) {
                for (int x = 0; x < m; x++) {
                    needs[i][x] = INT_MAX;
                    avail[x] += alloc[i][x];
                }
                final[size++] = i;
                break;
            }
        }
    }

    if (size == 0) {
        printf("DEADLOCK OCCURRED\n");
    } else if (size == n) {
        printf("SAFETY SEQUENCE\n");
        for (int i = 0; i < size; i++) {
            printf("p%d", final[i]);
            if (i != size - 1) {
                printf("-->");
            }
        }
        printf("\n");
    }

    printf("Final Available Resources --> ");
    for (int i = 0; i < m; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");

    return 0;
}

// output:
// Enter Number of Files : 3
// Enter size of hardDisk : 20
// Enter the start index of the File 1: 0
// Enter the length of the File 1: 5
// Enter the start index of the File 2: 2
// Enter the length of the File 2: 3
// Enter the start index of the File 3: 9
// Enter the length of the File 3: 6
// Hard Disk : 
// indices taken : 0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18      19
// Files taken   : 1       1       1       1       1       0       0       0       0       3       3       3       3       3       3       0       0       0       0       0