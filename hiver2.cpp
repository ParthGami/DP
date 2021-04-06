#include<bits/stdc++.h>
using namespace std;

int minJump(int row,int col)
{
    vector<vector<int>> dp(row+1,vector<int>(col+1,-1));
    dp[row][col] = 0;
    
    if((row-col) >= 0 && (row-col)<=(row)){
        dp[row-col][col] = 1;
    }
    
    if((col-row)>=0 && (col-row)<=(col)){
        dp[row][col-row] = 1;
    }

    for(int i=row;i>=0;i--){
        for(int j=col;j>=0;j--){
            if(i==row && j==col) continue;
            if(dp[i][j] == -1) continue;
            if((i-j)>=0 && (i-j)<=row && dp[i][j] != -1){
                dp[i-j][j] = dp[i][j] + 1;
            }
            if((j-i)>=0 && (j-i)<=(col) && dp[i][j] != -1){
                dp[i][j-i] = 1 + dp[i][j];
            }
        }
    }

    // for(int i=0;i<row+1;i++){
    //     for(int j=0;j<col+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[1][1];
}

int main()
{
    int row,col;
    cin>>row>>col;

    int ans = minJump(row,col);
    cout<<ans<<endl;
    return 0;
}