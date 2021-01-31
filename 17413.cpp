#include <iostream>
#include<stack>

using namespace std;

int main()
{
    stack<char> s;
    int n;
    char c;
    do{
        scanf("%1c",&c);
        if(c=='<'){
            while(s.empty()==false){
                cout<<s.top();
                s.pop();
            }
            cout<<c;
            do{
                scanf("%1c",&c);
                cout<<c;
            }while(c!='>');
            continue;
        }
        if(c==' ' || c=='\n'){
            while(s.empty()==false){
                cout<<s.top();
                s.pop();
            }
            cout<<c;
            continue;
        }
        s.push(c);
    }while(c!='\n');
    return 0;
}
