#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, j, k, min, n, f, pf = 0, next = 1;
    vector<int> rs(25), m(10, -1), count(10, 0), flag(25, 0);
    
    cout << "Enter the length of reference string -- ";
    cin >> n;
    
    cout << "Enter the reference string -- ";
    for (i = 0; i < n; i++) {
        cin >> rs[i];
    }
    
    cout << "Enter the number of frames -- ";
    cin >> f;
    
    cout << "\nThe Page Replacement process is -- \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                count[j] = next;
                next++;
            }
        }
        
        if (flag[i] == 0) {
            if (i < f) {
                m[i] = rs[i];
                count[i] = next;
                next++;
            } else {
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j]) {
                        min = j;
                    }
                }
                m[min] = rs[i];
                count[min] = next;
                next++;
            }
            pf++;
        }
        
        for (j = 0; j < f; j++) {
            cout << m[j] << "\t";
        }
        
        if (flag[i] == 0) {
            cout << "PF No. -- " << pf;
        }
        cout << "\n";
    }
    
    cout << "\nThe number of page faults using LRU are " << pf;
    
    return 0;
}


/*
    output:
    Enter the length of reference string -- 20
    Enter the reference string -- 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
    Enter the number of frames -- 3

    The Page Replacement process is -- 
    7       -1      -1      PF No. -- 1
    7       0       -1      PF No. -- 2
    7       0       1       PF No. -- 3
    2       0       1       PF No. -- 4
    2       0       1
    2       0       3       PF No. -- 5
    2       0       3
    4       0       3       PF No. -- 6
    4       0       2       PF No. -- 7
    4       3       2       PF No. -- 8
    0       3       2       PF No. -- 9
    0       3       2
    0       3       2
    1       3       2       PF No. -- 10
    1       3       2
    1       0       2       PF No. -- 11
    1       0       2
    1       0       7       PF No. -- 12
    1       0       7
    1       0       7

    The number of page faults using LRU are 12
*/