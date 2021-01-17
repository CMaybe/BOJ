#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[12];
int cnt[4];
int n;
long long _max=-1e9;
long long _min=1e9;

void func(int idx, int ans, int add, int sub, int mul, int div) {
    if (idx == n-1) {
        if (ans > _max) _max = ans;
        if (ans < _min) _min = ans;
        return;
    }
    if (add) func(idx+1, ans+arr[idx+1], add-1, sub, mul, div);
    if (sub) func(idx+1, ans-arr[idx+1], add, sub-1, mul, div);
    if (mul) func(idx+1, ans*arr[idx+1], add, sub, mul-1, div);
    if (div) func(idx+1, ans/arr[idx+1], add, sub, mul, div-1);
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<4;i++){
        cin>>cnt[i];
    }
    func(0, arr[0], cnt[0], cnt[1], cnt[2], cnt[3]);
    cout<<_max <<'\n';
    cout<<_min <<'\n';
    return 0;
}

