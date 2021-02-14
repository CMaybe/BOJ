#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n,len;
    cin>>n;
    cin>>len;
    string s;
    cin>>s;
    int cnt = 0,temp=0;
    for(int i = 1;i<len;i++){
        if(s[i-1]=='I'&&s[i]=='O'){
            temp++;
        }
        else if(s[i-1]=='O' && s[i]=='I'){
            if(temp>=n)cnt++;
        }
        else{
            temp=0;
        }
    }
    cout<<cnt;
    return 0;
}
