#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct TIME{
    int s;
    int e;
}Time;

bool compare(Time &a,Time&b){
    if(a.e==b.e){
        return a.s<b.s;
    }
    return a.e<b.e;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    vector<Time> v;
    int n,s,e;
    cin>>n;
    v.resize(n);
    for(int i = 0;i<n;i++){
        cin>>s>>e;
        v[i]=Time{s,e};
    }
    sort(v.begin(),v.end(),compare);
    int curTime = 0;
    int cnt = 0;
    for(int i =0;i<n;i++){
        if(curTime <= v[i].s){
            cnt++;
            curTime=v[i].e;
        }
    }
    cout<<cnt;
    return 0;
}
