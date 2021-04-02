#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                temp[i] = max(temp[i],temp[j]+1);
            }
        }
    }

    int max = temp[0];
    for(int i=1;i<n;i++){
        if(temp[i]>max){
            max = temp[i];
        }
    }
    return max; 
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int ans = LIS(vec);
    cout<<ans<<endl;
    return 0;
}