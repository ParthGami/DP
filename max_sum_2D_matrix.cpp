#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int> &temp,int &top,int &down){
    int sum=0;
    int maxSum = INT_MIN;
    int end = -1;
    for(int i=0;i<temp.size();i++){
        sum += temp[i];
        if(sum<0){
            sum=0;
            top=i+1;
        } 
        else if(sum>maxSum){
            maxSum = sum;
            end = i;
            down=i;
        } 
    }
    if(end != -1){
        return maxSum;
    }

    maxSum = temp[0];
    for(int i=0;i<temp.size();i++){
        if(maxSum<temp[i]){
            maxSum = temp[i];
            top=i;
            down=i;
        }
    }
    return maxSum;
}

int findSum(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int> temp(n,0);
    int result = INT_MIN;
    int tlc,lrc = 0;
    int start,end = 0;
    for(int leftCol=0;leftCol<m;leftCol++){
        temp.assign(n,0);
        for(int rightCol=leftCol;rightCol<m;rightCol++){
            for(int i=0;i<n;i++){
                temp[i] += arr[i][rightCol];
            }
            int sum = kadane(temp,start,end);
            // cout<<sum<<endl;
            if(sum > result){
                result = sum;
                tlc = leftCol;
                lrc = rightCol;
            }
        }
    }
    cout<<"From ("<<start<<","<<tlc<<")"<<endl;
    cout<<"To ("<<end<<","<<lrc<<")"<<endl;
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    int ans = findSum(vec);
    cout<<ans<<endl;
    return 0;
}