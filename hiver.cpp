#include<bits/stdc++.h>
using namespace std;

int maxSum(int n , string str)
{
    vector<int> vec;
    int ans = 1;
    string temp = "";
    for(int i=0;i<str.size();i++){
        if(str[i] >= '0' && str[i] <= '9'){
            temp += str[i];
        }
        else{
            if(temp.size() == 0) continue;
            vec.push_back(stoi(temp));
            temp = "";
        }
    }
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i]<<" ";
    // }

    int p = 0;
    vector<vector<int>> arr(n,vector<int>(n));
    // Input array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = vec[p++];
        }
    }

    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>> dp(n,vector<int>(n,0));
    int sum= arr[n-1][n-1];
    dp[n-1][n-1] = sum;
    for(int i=n-2;i>=0;i--){
        sum += arr[i][n-1];
        dp[i][n-1] = sum;
    }
    sum = arr[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        sum += arr[n-1][i];
        dp[n-1][i] = sum;
    }

    for(int i = n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j] = arr[i][j] + max(dp[i+1][j],dp[i][j+1]);
        }
    }
    //printing dp array
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[0][0];
}

int main()
{    
    int n;
    cin>>n;
    string str;
    cin>>str;
    int ans = maxSum(n,str);
    cout<<ans<<endl;
    return 0;
}