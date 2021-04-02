#include<bits/stdc++.h>
using namespace std;

int LCS(string text1,string text2)
{
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=0;i<n;i++){
        dp[0][i] = 1;
    }
   
    for(int i=0;i<m;i++){
        dp[i][0] = 0;     
    }

    for(int i=1;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string text1,text2;
    cin>>text1>>text2;

    int ans = LCS(text1,text2);
    cout<<ans<<endl;
    return 0;
}