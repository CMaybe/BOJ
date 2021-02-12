#include<algorithm>
#include <iostream>
#include<cmath>
#include<utility>
#include<vector>
using namespace std;
int arr[8002];

bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    vector<int> v;
    vector<pair<int,int>> p(8001);
    long long n;
    int mIdx=0;
    double sum=0;
    cin>>n;
    v.resize(n);
    int t=0;
    for(int i =0;i<n;i++){
        cin>>t;
        p[t+4000].first = t;
        p[t+4000].second++;
        v[i]=t;
        sum+=t;
    }
    sort(v.begin(),v.end());
    sort(p.begin(),p.end(),compare);
    int a;
    if(p[0].second==p[1].second)a=p[1].first;
    else a=p[0].first;
    cout<<(long long)round(sum/n)<<'\n'<<v[n/2]<<'\n'<<a<<'\n'<<(v[n-1]-v[0]);
    return 0;
}
