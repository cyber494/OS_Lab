#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter Number of Files : ";
    int n;
    cin>>n;
    cout<<"Enter size of hardDisk : ";
    int m;
    cin>>m;
    vector<string> fileName(n);
    vector<vector<int>> start(n,vector<int>(n));
    for(int i=0;i<n;i++){
        // cout<<"Enter the name of the File "<<i+1<<": ";
        // cin>>fileName[i];
        cout<<"Enter the start index of the File "<<i+1<<": ";
        cin>>start[i][0];
        cout<<"Enter the length of the File "<<i+1<<": ";
        cin>>start[i][1];
    }
    vector<int> hash(m,0);
    for(int i=0;i<n;i++){
        bool collide = false;
        int first = start[i][0];
        int last = start[i][0]+start[i][1];
        for(int j = first;j<last;j++){
            if(hash[j]!=0){
                collide = true;
                break;
            }
        }
        if(!collide){
            for(int j=first;j<last;j++){
                hash[j] = i+1;
            }
        }
    }
    cout<<"Hard Disk : "<<endl;
    cout<<"indices taken : ";
    for(int i=0;i<m;i++){
        cout<<i<<"\t";
    }
    cout<<endl;
    cout<<"Files taken   : ";
    for(int i=0;i<m;i++){
        cout<<hash[i]<<"\t";
    }
}
