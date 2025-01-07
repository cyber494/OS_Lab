//SJF
#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> bt(n), at(n), ct(n), wt(n), tat(n);
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

/*


Enter number of processes: 4
Enter the Arrival time of p1 : 1
Enter the Arrival time of p2 : 2
Enter the Arrival time of p3 : 1
Enter the Arrival time of p4 : 4
Enter the burst time of p1 : 3
Enter the burst time of p2 : 4
Enter the burst time of p3 : 2
Enter the burst time of p4 : 4

Bt      Ct      Tat     Wt
2       3       2       0
3       6       5       2
4       10      8       4
4       14      10      6
Average waiting time = 3
Average turnaround time = 6.25
*/