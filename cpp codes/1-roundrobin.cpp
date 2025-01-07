#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> pn(10),bt(10), ct(10), time(10), wt(10), tat(10);

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter process name and burst time of " << n << " processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> pn[i] >> bt[i];
        time[i] = bt[i];  
    }

    int tq;
    cout << "Enter quantum: ";
    cin >> tq;


    int full;
    full = n;  

    int temp = 0;
    while (full) {
        for (int i = 0; i < n; i++) {
            if (time[i] > 0) {
                if (time[i] > tq) {
                    time[i] -= tq;
                    temp += tq;
                } else {
                    temp += time[i];
                    time[i] = 0;
                    tat[i] = temp;  
                    full--;         
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ct[i] = tat[i];
        wt[i] = tat[i] - bt[i];
    }

    double avgwt = 0;
    cout << "\nPN\tBt\tCt\tTat\tWt"<<endl;
    for (int i = 0; i < n; i++) {
        cout << pn[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
        avgwt += wt[i];
    }

    avgwt = avgwt / n;
    cout << "\nAverage waiting time = " << avgwt << endl;

    return 0;
}



/*
    output :
    Enter number of processes: 5
    Enter process name and burst time of 5 processes:
    1 10
    2 5
    3 15
    4 3
    5 20
    Enter quantum: 5

    PN      Bt      Ct      Tat     Wt
    1      10      28      28      18
    2       5      10      10       5
    3      15      43      43      28
    4       3      18      18      15
    5      20      53      53      33

    Average waiting time = 19.80


*/