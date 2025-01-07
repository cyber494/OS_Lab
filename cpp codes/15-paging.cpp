#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    vector<int> s(10);
    vector<vector<int>> fno(10, vector<int>(20));

    cout << "\nEnter the memory size -- ";
    cin >> ms;
    cout << "\nEnter the page size -- ";
    cin >> ps;
    nop = ms / ps;
    cout << "\nThe no. of pages available in memory are -- " << nop;
    cout << "\nEnter number of processes -- ";
    cin >> np;
    rempages = nop;

    for (i = 1; i <= np; i++) {
        cout << "\nEnter no. of pages required for p[" << i << "] -- ";
        cin >> s[i];
        if (s[i] > rempages) {
            cout << "\nMemory is Full";
            break;
        }
        rempages = rempages - s[i];
        cout << "\nEnter pagetable for p[" << i << "] -- ";
        for (j = 0; j < s[i]; j++) {
            cin >> fno[i][j];
        }
    }

    cout << "\nEnter Logical Address to find Physical Address ";
    cout << "\nEnter process no. and page number and offset ";
    cin >> x >> y >> offset;
    if (x > np || y >= s[x] || offset >= ps) {
        cout << "\nInvalid Process or Page Number or offset";
    } else {
        pa = fno[x][y] * ps + offset;
        cout << "\nThe Physical Address is -- " << pa;
    }

    return 0;
}


/*
output:
Enter the memory size -- 1000

Enter the page size -- 100

The no. of pages available in memory are -- 10
Enter number of processes -- 3

Enter no. of pages required for p[1] -- 4

Enter pagetable for p[1] -- 8 6 9 5

Enter no. of pages required for p[2] -- 5

Enter pagetable for p[2] -- 1 4 5 7 3

Enter no. of pages required for p[3] -- 5

Memory is Full
Enter Logical Address to find Physical Address
Enter process no. and page number and offset 2 3 60

The Physical Address is -- 760


*/