//FCFS
#include <bits/stdc++.h>
using namespace std;
int main() {
    float sumwt = 0.0, sumtat = 0.0, avgwt, avgtat;
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    int bt[n], at[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time of p" <<i+1<<" : ";
        cin >> at[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time of p" <<i+1<<" : ";
        cin >> bt[i];
    }
    ct[0] = bt[0] - at[0];
    for (int i = 1; i < n; i++) {
        ct[i] = bt[i] + ct[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }


    avgwt = sumwt / n;
    avgtat = sumtat / n;

    cout << "\nPN\tBt\tCt\tTat\tWt"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "p"<<i+1 << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

  
    cout <<"Average waiting time = " << avgwt<<endl;
    cout <<"Average turnaround time = " <<avgtat <<endl;

    return 0;
}
