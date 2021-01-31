#include <iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n,m;
    stack<int> s;
    string ans="";
    cin>>n;
    int j=1;
    for(int i = 1;i<=n;i++){
        cin>>m;
        if(s.empty()==true){
            for(j;j<=m;j++){
                ans+="+\n";
                s.push(j);
            }
        }
        else{
            if(s.top() > m){
                ans="NO";
                break;
            }
            for(j;j<=m;j++){
                ans+="+\n";
                s.push(j);
            }
        }
        s.pop();
        ans+="-\n";
    }
    if(ans[0]=='N'){
        cout<<"NO";
    }
    else{
        cout<<ans;
    }
    return 0;
}
