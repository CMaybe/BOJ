#include <iostream>
#include <algorithm>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    stack<int> st;
    while(true){
        getline(cin,s);
        if(s==".")break;
        for(char c : s){
            if(c=='(' || c=='[') st.push(c);
            else if(c==')' && (!st.empty() && st.top()=='(')) st.pop();
            else if(c==']' && (!st.empty() &&st.top()=='[')) st.pop();
            else if(c==']' && (st.empty() ||st.top()!='[')) st.push(c);
            else if(c==')' && (st.empty() ||st.top()!='(')) st.push(c);
            
        }
        if(st.empty()){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
            while(!st.empty()){
                st.pop();
            }
        }
    }
    return 0;
}
