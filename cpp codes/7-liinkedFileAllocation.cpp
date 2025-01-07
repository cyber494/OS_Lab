#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Enter no. of files: ";
    cin >> n;

    vector<string> fname(n);
    vector<int> start(n), size(n);
    vector<vector<int>> block(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter file name: ";
        cin >> fname[i];
        cout << "Enter starting block: ";
        cin >> start[i];
        block[i].push_back(start[i]);
        cout << "Enter no. of blocks: ";
        cin >> size[i];
        cout << "Enter block numbers: ";
        for (int j = 0; j < size[i]; j++) {
            int blk;
            cin >> blk;
            block[i].push_back(blk);
        }
    }

    cout << "File\tstart\tsize\tblock\n";
    for (int i = 0; i < n; i++) {
        cout << fname[i] << "\t" << start[i] << "\t" << size[i] << "\t";
        for (int j = 0; j < size[i]; j++) {
            cout << block[i][j] << "--->";
        }
        cout << block[i][size[i]] << endl;
    }

    return 0;
}

/*
output:
Enter no. of files: 
2
Enter file name: abc
Enter starting block: 3
Enter no. of blocks: 3
Enter block numbers: 4 6 8
Enter file name: pqr
Enter starting block: 6
Enter no. of blocks: 6
Enter block numbers: 1 3 4 7 2 9
File    start   size    block
abc     3       3       3--->4--->6--->8
pqr     6       6       6--->1--->3--->4--->7--->2--->9

*/