#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<string>
using namespace std;

vector<pair<int,int>> v;


bool compare(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main()
{
    int t;
    
    cin >>t;
    for(int i = 0;i<t;i++){
        int h,w,n;
        cin>>h>>w>>n;
        v.clear();
        for(int j = 1;j<=h;j++){
            for(int k =1;k<=w;k++){
                v.push_back(make_pair(j,k));
            }
        }
        sort(v.begin(),v.end(),compare);
        cout<<v[n-1].first*100+v[n-1].second<<'\n';
    }
    
    return 0;
}
