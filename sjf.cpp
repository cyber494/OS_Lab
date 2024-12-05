//SJF
//https://gist.github.com/rahul-misala/c3186091745738538722f3e687fbdce5
#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> bt(n);
    vector<int> at(n);
    vector<int> ct(n);
    vector<int> wt(n);
    vector<int> tat(n);
    float sumwt, sumtat,avgwt, avgtat;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time of p" <<i+1<<" : ";
        cin >> at[i];
        mini = min(mini,at[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time of p" <<i+1<<" : ";
        cin >> bt[i];
    }

    sort(at.begin(),at.end());
    sort(bt.begin(),bt.end());
    
    ct[0] = bt[0]+mini;
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

    cout << "\nBt\tCt\tTat\tWt"<<endl;
    for (int i = 0; i < n; i++) {
        cout << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] <<endl;
    }

    cout << "Average waiting time = " << avgwt<<endl;
    cout << "Average turnaround time = " << avgtat <<endl;;

    return 0;
}
