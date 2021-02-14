#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    map<string,string> m;
    int n,k;
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        m[s1]=s2;
    }
    
    for(int i = 0;i<k;i++){
        string s1;
        cin>>s1;
        cout<<m[s1]<<'\n';
    }
    
    
    return 0;
}
