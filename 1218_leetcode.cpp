// This is giving TLE.
#include<bits/stdc++.h>
using namespace std;

int LAS(vector<int> &arr,int difference){
    int n = arr.size();
    vector<int> dp(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((arr[i]-arr[j]) == difference){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int max = dp[0];
    for(int i=1;i<n;i++){
        if(dp[i]>max)
            max = dp[i];
    }
    return max;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int ans = LAS(vec,k);
    cout<<ans<<endl;
    return 0;
}