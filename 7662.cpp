#include <iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int n;
        multiset<long long> v;
        cin>>n;
        string cmd;
        getline(cin,cmd);
        for(int j =0;j<n;j++){
            getline(cin,cmd);
            if(cmd[0]=='I'){
                cmd = cmd.substr(2,cmd.length()-2);
                long long t = stoi(cmd);
                v.insert(t);
            }
            else{
                cmd = cmd.substr(2,cmd.length()-2);
                int t = stoi(cmd);
                if(v.empty()) continue;
                if(t==1){
                    v.erase(v.lower_bound(*(v.rbegin())));
                }
                else{
                    v.erase(v.lower_bound(*(v.begin())));
                }
            }
        }
        if(v.empty()){
            cout<<"EMPTY\n";
        }
        else{
            cout<<(*v.rbegin())<<' '<<(*v.begin())<<'\n';
        }
    }
    
    
    return 0;
}
