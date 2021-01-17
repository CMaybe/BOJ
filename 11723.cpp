#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

bool arr[21];



int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    long long n,t;
    cin>>n;
    string cmd;
    for(int i=0;i<n;i++){
        cin>>cmd;
        if(cmd == "add"){
            cin>>t;
            arr[t] =true;
        }
        else if(cmd == "remove"){
            cin>>t;
            arr[t]=false;
        }
        else if(cmd == "check"){
            cin>>t;
            int i=arr[t];
            cout <<  i <<'\n';
        }
        else if(cmd == "toggle"){
            cin>>t;
            arr[t] = !arr[t];
        }
        else if(cmd == "all"){
            for(int j =0;j<=20;j++){
                arr[j]=true;
            }
        }
        else if(cmd == "empty"){
            for(int j =0;j<=20;j++){
                arr[j]=false;
            }
        }
    }

    return 0;
}

