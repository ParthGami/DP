#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));

    dp[m-1][n-1] = grid[m-1][n-1];
    int sum=0;
    
    for(int i=m-1;i>=0;i--){
        sum += grid[i][n-1];
        dp[i][n-1] = sum;
    }
    sum=0;
    for(int i=n-1;i>=0;i--){
        sum += grid[m-1][i];
        dp[m-1][i] = sum;
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> vec(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }

    int ans = minPathSum(vec);
    cout<<ans<<endl;
    return 0;
}