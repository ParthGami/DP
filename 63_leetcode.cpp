#include<bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>> &obstacleGrid){

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));

    if(!obstacleGrid[0][0])
        dp[0][0] = 1;

    for(int i=1;i<m;i++){
        if(obstacleGrid[i][0] || dp[i-1][0]==0){
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = 1;
        }
    }

    for(int i=1;i<n;i++){
        if(obstacleGrid[0][i] || dp[0][i-1]==0){
            dp[0][i] = 0;
        }
        else{
            dp[0][i] = 1;
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]){
                dp[i][j] = 0;
            }
            else 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];

}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> vec(m,vector<int>(n,0));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }

    int ans = uniquePaths(vec);
    cout<<ans<<endl;
    return 0;
}