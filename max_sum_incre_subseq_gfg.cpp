#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n);

    dp = arr;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i],dp[j]+arr[i]);
            }
        }
    }

    int max = dp[0];
    for(int i=1;i<n;i++){
        if(dp[i]>max){
            max = dp[i];
        }
    }
    return max;
}

int main()
{
    int n;
    cin>>n;

    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int ans = maxSum(vec);
    cout<<ans<<endl;
    return 0;
}