#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int n,s,cnt=0;
int arr[20];
void func(int idx,int sum){
    if (sum==s)cnt++;
    for(int i = 1;i+idx<n;i++){
        func(idx+i,sum+arr[i+idx]);
    }
}


int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >> n >>s;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i<n;i++){
        int sum=arr[i];
        func(i,sum);
    }
    cout<<cnt;
    return 0;
}
