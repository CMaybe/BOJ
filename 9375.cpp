#include <iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    cin>>t;
   
    for(int i = 0;i<t;i++){
        int n;
        cin>>n;
        string name,cate;
        map<string,int> cl;
        for(int j=0;j<n;j++){
            cin>>name>>cate;
            cl[cate]++;
        }
        long long ans=1;
        for(auto &it : cl){
            ans *= it.second+1;
        }
        cout<<ans-1<<'\n';
        
    }
    
    return 0;
}
