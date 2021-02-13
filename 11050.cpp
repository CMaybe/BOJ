#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<string>
using namespace std;

int fac(int n){
    int t=1;
    for(int i =1;i<=n;i++){
        t*=i;
    }
    return t;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(0);
    int n,k;
    cin>>n>>k;
    cout<<fac(n)/(fac(k)*fac(n-k));
    return 0;
}
