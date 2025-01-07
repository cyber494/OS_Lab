#include <stdio.h>
#include <conio.h>

int main() {
    int avl_partitions, ms, i, j, ps[20], n, p[20], s, intr = 0;
    float size;

    printf("Enter size of memory: ");
    scanf("%d", &ms);

    printf("Enter memory for OS: ");
    scanf("%d", &s);

    ms -= s;

    printf("Enter no.of partitions to be divided: ");
    scanf("%d", &n);
    printf("\n");

    size = ms / n;
    printf("The available size of each partition is %f", size);
    printf("\n");

    avl_partitions = n;
    i = 0;
    j = 0;

    while (1) {
        printf("Enter process size: ");
        scanf("%d", &ps[i]);

        if (ps[i] <= size) {
            intr = intr + size - ps[i];
            printf("process%d is allocated to partition %d\n", i, j);

            i = i + 1;
            j = j + 1;
            avl_partitions = avl_partitions - 1;
            printf("\n");
        } else {
            printf("process%d is blocked\n", i);
            i = i + 1;
        }

        if (avl_partitions == 0)
            break;
    }

    printf("total fragmentation is %d", intr);
    getch();

    return 0;
}


/*
output:
    Enter size of memory: 50
    Enter memory for OS: 10
    Enter no.of partitions to be divided: 5

    The available size of each partition is 8.000000
    Enter process size: 10
    process0 is blocked
    Enter process size: 8
    process1 is allocated to partition 0

    Enter process size: 7
    process2 is allocated to partition 1

    Enter process size: 12
    process3 is blocked
    Enter process size: 4
    process4 is allocated to partition 2

    Enter process size: 5
    process5 is allocated to partition 3

    Enter process size: 9
    process6 is blocked
    Enter process size: 5
    process7 is allocated to partition 4

    total fragmentation is 11

*/