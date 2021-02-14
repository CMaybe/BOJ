#include <iostream>
#include<set>
#include<iterator>
#include<vector>
using namespace std;

long long arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    set<long long> s;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    vector<long long> v(s.begin(),s.end());
    for(int i = 1;i<=n;i++){
        cout<<lower_bound(v.begin(),v.end(),arr[i]) - v.begin()<<' ';
    }
    return 0;
}
