#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int m, f, pf = 0;
    cout << "Enter number of page references -- ";
    cin >> m;

    vector<int> rs(m);
    cout << "Enter the reference string -- ";
    for (int i = 0; i < m; i++)
        cin >> rs[i];

    cout << "Enter the available no. of frames -- ";
    cin >> f;

    vector<int> cntr(f, 0), a(f, -1);

    cout << "\nThe Page Replacement Process is – \n";
    for (int i = 0; i < m; i++) {
        int j;
        for (j = 0; j < f; j++) {
            if (rs[i] == a[j]) {
                cntr[j]++;
                break;
            }
        }

        if (j == f) {
            int min = 0;
            for (int k = 1; k < f; k++) {
                if (cntr[k] < cntr[min])
                    min = k;
            }

            a[min] = rs[i];
            cntr[min] = 1;
            pf++;
        }

        cout << "\n";
        for (int j = 0; j < f; j++)
            cout << "\t" << a[j];

        if (j == f)
            cout << "\tPF No. " << pf;
    }

    cout << "\n\nTotal number of page faults -- " << pf << endl;

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
