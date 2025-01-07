//PRIORITY SCHEDULING
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    vector<int> bt(n), p(n), ct(n), wt(n), tat(n);
    cout << "Enter the Burst time of " <<n<<" processess : ";
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
    }
    cout << "Enter the priority of " <<n<<" processes : ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    sort(p.begin(),p.end(),greater<int>());
    sort(bt.begin(),bt.end(),[&](int i,int j){
        return p[i]>p[j];
    });

    ct[0] = bt[0];
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        ct[i] = bt[i] + ct[i - 1];
    }
    float sumwt, sumtat, avgwt, avgtat;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }


    avgwt = sumwt / n;
    avgtat = sumtat / n;

    cout << "\nBt\tCt\tTat\tWt"<<endl;
    for (int i = 0; i < n; i++) {
        cout << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    cout <<"Average waiting time = "<< avgwt<<endl;
    cout <<"Average turnaround time = "<< avgtat << endl;

    return 0;
}