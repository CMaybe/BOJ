#include <iostream>
#include<queue>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    int ans =n/5;
    if(n%5>0)ans++;
    cout<<ans;
    
    return 0;
}
