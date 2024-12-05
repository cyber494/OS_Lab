//Bankers Avoidance
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of Processess : ";
    cin>>n;
    cout<<"Enter the number of Resources : ";
    cin>>m;
    vector<vector<int>> alloc(n,vector<int>(m));
    vector<vector<int>> maxi(n,vector<int>(m));
    vector<vector<int>> needs(n,vector<int>(m));
    for(int i=0;i<n;i++){
        cout<<"Enter the p"<<i<<" Allocation Resources one by one";
        for(int j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cout<<"Enter the p"<<i<<" Maximum Resources one by one";
        for(int j=0;j<m;j++){
            cin>>maxi[i][j];
            needs[i][i] = maxi[i][j] - alloc[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cout<<"Needs of p"<<i<<" ";
        for(int j=0;j<m;j++){
            cout<<needs[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter Initial Available resources of p0 : ";
    vector<int> avail(m);
    for(int i=0;i<m;i++){
        cin>>avail[i];
    }
    vector<int> final;
    for(int y=0;y<n;y++){
        for(int i=0;i<n;i++){
            int execute=0;
            for(int j=0;j<m;j++){
                if(needs[i][j]<=avail[j]){
                    execute++;
                }
            }
            if(execute==m){
                for(int x=0;x<m;x++){
                    needs[i][x] = INT_MAX;
                    avail[x] += alloc[i][x];
                }
                final.push_back(i);
                break;
            }
        }
    }
    int size = final.size();
    if(size==0){
        cout<<"DEADLOCK OCCURED"<<endl;
    }else if(size==n){
        cout<<"SAFETY SEQUENCE"<<endl;
    }
    for(int i=0;i<size;i++){
        cout<<"p"<<i;
        if(i!=size-1){
            cout<<"-->";
        }
    }
    cout<<endl;
    cout<<"Final Available Resources --> ";
    for(int i=0;i<m;i++){
        cout<<avail[i]<<" ";
    }
}

// output:
// Enter Number of Files : 3
// Enter size of hardDisk : 20
// Enter the start index of the File 1: 0
// Enter the length of the File 1: 5
// Enter the start index of the File 2: 2
// Enter the length of the File 2: 3
// Enter the start index of the File 3: 9
// Enter the length of the File 3: 6
// Hard Disk : 
// indices taken : 0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18      19
// Files taken   : 1       1       1       1       1       0       0       0       0       3       3       3       3       3       3       0       0       0       0       0