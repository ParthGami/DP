#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1,string word2){
    
    if(word1.empty()){
        return word2.size();
    }

    if(word2.empty()){
        return word1.size();
    }
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=0;i<n+1;i++){
        dp[0][i] = i; 
    }

    for(int i=0;i<m+1;i++){
        dp[i][0] = i;
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
            
        }
    }
    return dp[m][n];
}

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    int ans = minDistance(str1,str2);
    cout<<ans<<endl;
    return 0;
}