//PRIORITY SCHEDULING
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Enter number of processes: ";
    int n;
    cin >> n;

    int bt[n], p[n],ct[n], wt[n], tat[n];
    cout << "Enter the Burst time of " <<n<<" processess : ";
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
    }
    cout << "Enter the priority of " <<n<<" processes : ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
            }
        }
    }

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