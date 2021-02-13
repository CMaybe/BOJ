#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin>>a;
    cout<<a/100*78<<' '<<a/100*80  + (a/5 * 78/100);
    
    return 0;
}
