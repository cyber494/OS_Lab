#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int i, j, k, f, pf = 0, n;
    vector<int> rs(25);
    queue<int> m;
    
    cout << "\n Enter the length of reference string -- ";
    cin >> n;
    
    cout << "\n Enter the reference string --";
    for (i = 0; i < n; i++)
        cin >> rs[i];
    
    cout << "\n Enter no. of frames -- ";
    cin >> f;
    
    vector<int> frames(f, -1);
    
    cout << "\n The Page Replacement Process is --\n";
    for (i = 0; i < n; i++) {
        bool found = false;
        for (k = 0; k < f; k++) {
            if (frames[k] == rs[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            if (m.size() == f) {
                int oldest = m.front();
                m.pop();
                for (j = 0; j < f; j++) {
                    if (frames[j] == oldest) {
                        frames[j] = rs[i];
                        break;
                    }
                }
            } else {
                frames[m.size()] = rs[i];
            }
            m.push(rs[i]);
            pf++;
        }
        for (j = 0; j < f; j++)
            cout << "\t" << frames[j];
        if (!found)
            cout << "\tPF No." << pf;
        cout << "\n";
    }
    
    cout << "\n The number of Page Faults using FIFO are " << pf;
    
    return 0;
}


/*
output:

    Enter the length of reference string -- 20

    Enter the reference string --7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

    Enter no. of frames -- 3

    The Page Replacement Process is --
            7       -1      -1      PF No.1
            7       0       -1      PF No.2
            7       0       1       PF No.3
            2       0       1       PF No.4
            2       0       1
            2       3       1       PF No.5
            2       3       0       PF No.6
            4       3       0       PF No.7
            4       2       0       PF No.8
            4       2       3       PF No.9
            0       2       3       PF No.10
            0       2       3
            0       2       3
            0       1       3       PF No.11
            0       1       2       PF No.12
            0       1       2
            0       1       2
            7       1       2       PF No.13
            7       0       2       PF No.14
            7       0       1       PF No.15

    The number of Page Faults using FIFO are 15


*/