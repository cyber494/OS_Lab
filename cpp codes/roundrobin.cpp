//ROUND ROBIN
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    int bt[n], ct[n], time[n], tat[n], wt[n];
    cout << "Enter the Burst time of " <<n<<" processess : ";
    for (int i = 0; i < n; i++) {
        cin >>bt[i];
        time[i] = bt[i];
    }
    cout << "Enter quantum: ";
    int tq;
    cin >> tq;
    int full = n;
    int time1=0;
    while (full) {
        for (int i = 0; i < n; i++) {
            if (bt[i] >= tq) {
                bt[i] -= tq;
                time1 += tq;
            } else if (bt[i] > 0) {
                time1 += bt[i];
                bt[i] = 0;
            }

            if (bt[i] == 0 && time[i] != -1) {
                full--;
                tat[i] = time1;
                time[i] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ct[i] = tat[i];
        wt[i] = tat[i] - time[i];
    }
    float avgwt = 0;
    cout << "PN\tBt\tCt\tTat\tWt"<<endl;
    for (int i = 0; i < n; i++) {
        cout <<"p"<<i+1<< "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t"<<endl;
        avgwt += wt[i];
    }
    avgwt /= n;
    cout << "\nAverage waiting time = " << avgwt << "\n";
    return 0;
}
