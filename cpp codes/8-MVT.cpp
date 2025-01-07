#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i, m, n, tot;
    vector<int> s(20);

    cout << "Enter total memory size: ";
    cin >> tot;
    cout << "Enter no. of processes: ";
    cin >> n;
    cout << "Enter memory for OS: ";
    cin >> m;

    for (i = 0; i < n; i++) {
        cout << "Enter size of process " << i + 1 << ": ";
        cin >> s[i];
    }

    tot = tot - m;

    for (i = 0; i < n; i++) {
        if (tot >= s[i]) {
            cout << "Allocate memory to process " << i + 1 << endl;
            tot = tot - s[i];
        } else {
            cout << "Process p" << i + 1 << " is blocked" << endl;
        }
    }

    cout << "External Fragmentation is = " << tot << endl;

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
