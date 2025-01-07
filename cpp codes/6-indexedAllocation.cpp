#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> ib(20), m(20);
    vector<vector<int>> b(20, vector<int>(20));

    cout << "Enter no. of files: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter index block for file " << i + 1 << ": ";
        cin >> ib[i];
        cout << "Enter blocks occupied by file " << i + 1 << ": ";
        cin >> m[i];
        cout << "Enter blocks of file " << i + 1 << ": ";
        for (int j = 0; j < m[i]; j++) {
            cin >> b[i][j];
        }
    }

    cout << "\nFile\tIndex\tLength\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << ib[i] << "\t" << m[i] << "\n";
    }

    cout << "Blocks occupied are:\n";
    for (int i = 0; i < n; i++) {
        cout << "File no " << i + 1 << ": ";
        for (int j = 0; j < m[i]; j++) {
            cout << "\t" << ib[i] << " ---> " << b[i][j] << "\n";
        }
        cout << "\n";
    }

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
