#include<bits/stdc++.h>
using namespace std;

int LAS(vector<int> &arr,int difference)
{
    int minl = *min_element(arr.begin(),arr.end());
    int maxl = *max_element(arr.begin(),arr.end());

    int range = maxl - minl+1;
    vector<int> dp(range,0);
    int ans = 1;
    int curr,prev;

    for(int i=0;i<arr.size();i++){

        curr = arr[i] - minl;
        dp[curr] = 1;

        prev = curr - difference;
        if(prev>=0 && prev<range){
            dp[curr] = max(dp[curr],dp[prev]+dp[curr]);
        }
        ans = max(ans,dp[curr]);
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = LAS(arr,k);
    cout<<ans<<endl;
    return 0;
}