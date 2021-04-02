#include<bits/stdc++.h>
using namespace std;

pair<int,int> getMaxMin(vector<int> &arr,int k,int x)
{
    int n = arr.size();
    sort(arr.begin(),arr.end());
    pair<int,int> ans;

    if(k%2 == 0){
        ans.first = arr[n-1];
        ans.second = arr[0];
        return ans;
    }
    else{
        for(int i=0;i<n;i+=2){
            int temp = (arr[i] ^ x);
            arr[i] = temp;
        }
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        ans.first = arr[n-1];
        ans.second = arr[0];
        return ans;
    }
}

int main()
{
    int n,k,x;
    cin>>n>>k>>x;

    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    pair<int,int> ans = getMaxMin(vec,k,x);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}