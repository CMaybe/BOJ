#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double a,b,c;
    cin>>a>>b>>c;
    cout<<(int)((++a*++b)/(c+1)-1);
    
    return 0;
}
