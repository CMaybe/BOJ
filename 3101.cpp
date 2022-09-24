#include <iostream>
#include <string>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,k,x=1,y=1;
    string s;
    cin >> n >>k;
    cin >> s;
    long long ans = 1;
    for(int i = 0;i<k;i++){
        if(s[i]=='U') y--;
        else if(s[i]=='D') y++;
        else if(s[i]=='R') x++;
        else if(s[i]=='L') x--;
        long long idx = x + y - 1;
        long long t = idx > n ? idx - n : 0;
        if(idx % 2 == 1) ans += idx * (idx - 1) / 2 + x - t * t;
        else ans += idx * (idx + 1) / 2 - x + 1 - t * t;
    }
    cout << ans;
    
}
