#include<algorithm>
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    vector<long long> v;
    long long n,m;
    cin>>n;
    v.resize(n);
    long long t=0;
    for(int i =0;i<n;i++){
        cin>>t;
        v[i]=t;
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(int i = 0;i<m;i++){
        bool flag=false;
        cin>>t;
        int _min = 0;
        int _max = n-1;
        while(_min<=_max){
            int idx = (_min+_max)/2;
            if(v[idx]<t){
                _min=idx+1;
                continue;
            }
            if(v[idx]>t){
                _max=idx-1;
                continue;
            }
            flag = true;
            cout<<"1\n";
            break;
        }
        if(flag==false)
            cout<<"0\n";
    }
    
    return 0;
}
