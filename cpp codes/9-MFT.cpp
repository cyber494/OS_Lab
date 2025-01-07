#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int avl_partitions, ms, i, j, ps[20], n, p[20], s, intr = 0;
    float size;

    cout << "Enter size of memory: ";
    cin >> ms;

    cout << "Enter memory for OS: ";
    cin >> s;

    ms -= s;

    cout << "Enter no.of partitions to be divided: ";
    cin >> n;
    cout << "\n";

    size = ms / n;
    cout << "The available size of each partition is " << size;
    cout << "\n";

    avl_partitions = n;
    i = 0;
    j = 0;

    while (1) {
        cout << "Enter process size: ";
        cin >> ps[i];

        if (ps[i] <= size) {
            intr = intr + size - ps[i];
            cout << "process" << i << " is allocated to partition " << j << "\n";

            i = i + 1;
            j = j + 1;
            avl_partitions = avl_partitions - 1;
            cout << "\n";
        } else {
            cout << "process" << i << " is blocked\n";
            i = i + 1;
        }

        if (avl_partitions == 0)
            break;
    }

    cout << "total fragmentation is " << intr;

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