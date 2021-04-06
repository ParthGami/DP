#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &temp, int k)
{
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < temp.size(); i++)
    {
        sum += temp[i];
        // if(sum<0){
        //     sum = 0;
        // }
        if (sum > maxSum && sum <= k)
        {
            maxSum = sum;
        }
    }
    return maxSum;
}

vector<int> findSum(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<int> ans;
    vector<int> temp(n, 0);
    int sum;
    for (int i = 0; i < m; i++)
    {
        temp.assign(n, 0);
        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[k] += arr[k][j];
            }
            sum = kadane(temp, k);
            cout << sum << " ";
            ans.push_back(sum);
            // if(sum>result){
            //     result = sum;
            // }
        }
    }
    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    int k;
    cin >> k;
    vector<int> ans = findSum(vec, k);
    int max = ans[0];

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] > max)
        {
            max = ans[i];
        }
    }
    cout << max << endl;
    return 0;
}