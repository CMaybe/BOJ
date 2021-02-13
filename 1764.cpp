#include <iostream>
#include<string>
#include<set>
#include<vector>
#include<cstring>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    set<string> v;
    set<string> ans;
    string s;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>s;
        v.insert(s);
    }
    
    for(int i = 0;i<m;i++){
        cin>>s;
        if(v.find(s)!=v.end())
            ans.insert(s);
    }
    cout<<ans.size()<<'\n';
    for(string t : ans){
        cout<<t<<'\n';
    }
    return 0;
}
