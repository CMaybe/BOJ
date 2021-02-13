#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a1,b1,c1,a2,b2,c2,t;
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;
    cout<<a2-c1<<' '<<b2/b1<<' '<<c2-a1;
    return 0;
}
