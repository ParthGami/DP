#include<bits/stdc++.h>
using namespace std;

int totalWays(vector<int> &coins,int amount)
{
    if(amount==0)
        return 1;
        
    if(coins.size()==0)
        return 0;

    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=amount;i++){
        if(i%coins[0] == 0){
            dp[0][i] = 1;
        }else{
            dp[0][i] = 0;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i] > -1){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n-1][amount];
}

int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cin>>amount;
    int ans = totalWays(coins,amount);
    cout<<ans<<endl;
    return 0;
}