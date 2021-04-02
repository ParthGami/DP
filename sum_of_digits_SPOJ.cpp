#include<bits/stdc++.h>
using namespace std;

long long int power_of_n(long long int n){
    long long int result = 1;
    for(long long int i=1;i<=n;i++){
        result *= 10;
    }
    return result;
}

long long int sum_of_digits(long long int num){

    if(num/10 == 0){
        return (num*(num+1))/2;
    }

    string str  = to_string(num);
    int no_of_digits = str.size();
    int first = num / power_of_n(no_of_digits-1);

    long long int result=0;
    for(int i=0;i<first;i++){
        result += i*power_of_n(no_of_digits-1) + power_of_n(no_of_digits-2)*45*(no_of_digits-1);
    }

    long long int remain = num % power_of_n(no_of_digits-1);
    result += first*(remain+1);
    result += sum_of_digits(remain);
    return result;
}

int main()
{
    long long int m,n;
    while(true){
        cin>>m>>n;
        if(m==-1 && n==-1) break;

        long int x = sum_of_digits(n);
        long int y = sum_of_digits(m-1);
        cout<<x-y<<" ";
    }
    return 0;
}