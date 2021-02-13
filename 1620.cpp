#include <iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    map<int,string> is;
    map<string,int> si;
    cin>>n>>m;
    string s;
    for(int i = 1;i<=n;i++){
        cin>>s;
        si[s]=i;
        is[i]=s;
    }
    for(int i  =0;i<m;i++){
        cin>>s;
        if(s[0]>'0' && s[0]<='9'){
            int n = stoi(s);
            cout<<is[n]<<'\n';
        }
        else cout<<si[s]<<'\n';
        
    }
    
    return 0;
}
