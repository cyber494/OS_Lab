#include <stdio.h>
#include <conio.h>

int main() {
    int i, m, n, tot, s[20];

    printf("Enter total memory size: ");
    scanf("%d", &tot);
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter memory for OS: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &s[i]);
    }

    tot = tot - m;

    for (i = 0; i < n; i++) {
        if (tot >= s[i]) {
            printf("Allocate memory to process %d\n", i + 1);
            tot = tot - s[i];
        } else {
            printf("Process p%d is blocked\n", i + 1);
        }
    }

    printf("External Fragmentation is = %d", tot);
    getch();

    return 0;
}


/*
output:
Enter total memory size: 50
Enter no. of processes: 6
Enter memory for OS: 10
Enter size of process 1: 20
Enter size of process 2: 34
Enter size of process 3: 2
Enter size of process 4: 5
Enter size of process 5: 23
Enter size of process 6: 1
Allocate memory to process 1
Process p2 is blocked
Allocate memory to process 3
Allocate memory to process 4
Process p5 is blocked
Allocate memory to process 6
External Fragmentation is = 12

*/