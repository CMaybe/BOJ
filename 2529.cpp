#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool visit[10];
char syms[10];
int n;
vector<string> ans;
void dfs(string s,int cnt,int num){
    if(cnt==n){
        ans.push_back(s);
        return;
    }
    for(int i = 0;i<=9;i++){
        if(visit[i]) continue;
        if(syms[cnt] == '<'){
            if(num < i ){
                visit[i]=true;
                dfs(s+to_string(i),cnt+1,i);
                visit[i]=false;
            }
        }
        
        if(syms[cnt] == '>'){
            if(num > i ){
                visit[i]=true;
                dfs(s+to_string(i),cnt+1,i);
                visit[i]=false;
            }
        }
    }
    
} 
int main()
{
    cin>>n;
    n++;
    for(int i = 1;i<=n;i++){
        cin>>syms[i];
    }
    for(int i=0;i<=9;i++){
        visit[i]=true;
        dfs(to_string(i),1,i);
        visit[i]=false;
    }
    sort(ans.begin(),ans.end());
    string _min=ans[0];
    string _max=ans[ans.size()-1];
    cout<<_max<<'\n'<<_min;
    return 0;
}
