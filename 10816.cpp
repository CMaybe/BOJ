#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<string>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(0);
    int * arr = new int[20000001];
    int t,n;
    cin >>t;
    for(int i =0;i<t;i++){
        cin>>n;
        arr[n+10000000]++;
    }
    cin >>t;
    for(int i =0;i<t;i++){
        cin>>n;
        cout<<arr[n+10000000]<<' ';
    }

    return 0;
}
