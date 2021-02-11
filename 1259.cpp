#include <iostream>
#include<string>

using namespace std;

int main() {
    int n;
    string s;
    while(true){
        bool flag = true;
        cin>>s;
        if(s=="0")break;
        for(int i =0;i<s.size()/2 && flag;i++){
            if(s[i]!=s[s.size()-1-i]){ 
                cout<<"no\n";
                flag = false;
            }
        }
        if(flag) cout<<"yes\n";
    }
}
