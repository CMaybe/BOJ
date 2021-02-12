#include <iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

int syms[26];


vector<pair<char,int>> p;
string temp;
int M = -1;     

bool compare(pair<char,int>& a,pair<char,int>& b){
    return a.second>b.second;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<26;i++){
        p.push_back(make_pair('A'+i,0));
    }
    for(int i = 0;i<n;i++){
        cin>>temp;
        reverse(temp.begin(),temp.end());
        int weight=1;
        for(int j =0;j<temp.length();j++){
            p[temp[j]-'A'].second+=weight;
            weight*=10;
        }
    }
    
    sort(p.begin(),p.end(),compare);
    int d=9;
    int ans = 0;
    for(auto t : p){
        ans += (d--)*t.second;
    }
    cout<<ans;

    
    return 0;
}
