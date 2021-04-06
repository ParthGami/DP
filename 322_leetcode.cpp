#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins,int amount)
{
    int m = coins.size();
    sort(coins.begin(),coins.end());
    vector<vector<int>> dp(m,vector<int>(amount+1,amount+1));

    for(int j=1;j<amount+1;j++){
        if(j%coins[0]==0){
            dp[0][j] = j/coins[0];
        }// else{
        //     dp[0][j] = -1;
        // }
    }

    for(int i=0;i<m;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<=amount;j++){
            // if(j<coins[i]){
            //     dp[i][j] = dp[i-1][j];
            // }
            // // else if(j>=coins[i] && j%coins[i]==0){
            // //     dp[i][j] = j/coins[i];
            // // }
            // else if(j>=coins[i] && (dp[i][j-coins[i]] != -1 && dp[i-1][j] != -1)){
            //     dp[i][j] = min(1+dp[i][j-coins[i]],dp[i-1][j]);
            // }
            // else if(j>=coins[i] && dp[i-1][j] == -1){
            //     dp[i][j] = 1+dp[i][j-coins[j]];
            // }
            // else if(j>=coins[i] && dp[i][j-coins[i]] == -1){
            //     dp[i][j] = dp[i-1][j];
            // }

            // if(j<coins[i])
            //     dp[i][j] = dp[i-1][j];
            // else if(j>=coins[i] && dp[i-1][j] == -1){
            //     if(dp[i][j-coins[i]] != -1)
            //         dp[i][j] = 1+dp[i][j-coins[i]];
            // }
            // else if(j>=coins[i] && dp[i][j-coins[i]] == -1){
            //     if(dp[i-1][j] != -1)
            //         dp[i][j] = dp[i-1][j];
            // }
            // else{
            //     dp[i][j] = min(1+dp[i][j-coins[i]],dp[i-1][j]);
            // }

            if(j-coins[i]>=0){
                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i]]);
            }
        }
    }
    return dp[m-1][amount]>amount ? -1 : dp[m-1][amount];
}

int main()
{
    int amount,n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cin>>amount;
    int ans = minCoins(coins,amount);
    cout<<ans<<endl;
    return 0;
}