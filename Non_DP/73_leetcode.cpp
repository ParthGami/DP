#include<bits/stdc++.h>
using namespace std;

void setZero(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int,int>> temp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                temp.push_back(make_pair(i,j));
            }
        }
    }
    for(auto i:temp){
        int a = i.first;
        int b = i.second;
        for(int j=0;j<n;j++){
            matrix[a][j] = 0;
        }
        for(int j=0;j<m;j++){
            matrix[j][b] = 0;
        }
    }
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    setZero(arr);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}