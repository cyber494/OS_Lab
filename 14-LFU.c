#include <stdio.h>
#include <conio.h>

int main() {
    int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf = 0;
    
    printf("\nEnter number of page references -- ");
    scanf("%d", &m);
    
    printf("\nEnter the reference string -- ");
    for (i = 0; i < m; i++)
        scanf("%d", &rs[i]);
    
    printf("\nEnter the available no. of frames -- ");
    scanf("%d", &f);
    
    for (i = 0; i < f; i++) {
        cntr[i] = 0;
        a[i] = -1;
    }
    
    printf("\nThe Page Replacement Process is – \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < f; j++) {
            if (rs[i] == a[j]) {
                cntr[j]++;
                break;
            }
        }
        
        if (j == f) {
            min = 0;
            for (k = 1; k < f; k++) {
                if (cntr[k] < cntr[min])
                    min = k;
            }
            
            a[min] = rs[i];
            cntr[min] = 1;
            pf++;
        }
        
        printf("\n");
        for (j = 0; j < f; j++)
            printf("\t%d", a[j]);
        
        if (j == f)
            printf("\tPF No. %d", pf);
    }
    
    printf("\n\n Total number of page faults -- %d", pf);
    getch();
    
    return 0;
}
/*
    output:

    Enter number of page references -- 10

    Enter the reference string -- 1 2 3 4 5 2 5 1 4 3

    Enter the available no. of frames -- 3

    The Page Replacement Process is ΓÇô

            1       -1      -1      PF No. 1
            1       2       -1      PF No. 2
            1       2       3       PF No. 3
            4       2       3       PF No. 4
            5       2       3       PF No. 5
            5       2       3       PF No. 5
            5       2       3       PF No. 5
            5       2       1       PF No. 6
            5       2       4       PF No. 7
            5       2       3       PF No. 8

    Total number of page faults -- 8


*/
