#include<bits/stdc++.h>
using namespace std;

int dp[105][105][2];
int bitsCount(int n,int k,int f){
    if(n==0)
        return 0;
    
    if(n==1){
        if(k==0){
            return 1;
        }
        else
            return 0;
    }

    if(dp[n][k][f] != -1)  return dp[n][k][f];

    long long retval = -1;

    if(f==1){
        retval = bitsCount(n-1,k,0) + bitsCount(n-1,k-1,1);
    }else{
        retval = bitsCount(n-1,k,0) + bitsCount(n-1,k,1);
    }
    return dp[n][k][f] = retval;
}

int main()
{
    int t,n,k;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        long long int ans = bitsCount(n,k,0);
        ans += bitsCount(n,k,1);
        cout<<ans<<endl;
    }
    return 0;
}