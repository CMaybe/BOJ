#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long n,m,n2=0,n5=0;
    cin >>n>>m;
    if (n == m || m == 0) {
        cout << 0;
        return 0;
    }
    
    long long i=0;

    for (i = 2; i <= n; i *= 2) n2 += n / i;
    for (i = 2; i <= m; i *= 2) n2 -= m / i;
    for (i = 2; i <= n - m; i *= 2) n2 -= (n - m) / i;
    
    for (i = 5; i <= n; i *= 5) n5 += n / i;
    for (i = 5; i <= m; i *= 5) n5 -= m / i;
    for (i = 5; i <= n - m; i *= 5) n5 -= (n - m) / i;
    
    long long ans = min(n2, n5);
    cout << ans;
    return 0;
}

