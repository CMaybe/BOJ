#include <iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int func(char c){
	if(c=='(') return 0;
	else if(c=='+' || c=='-') return 1;
	else if(c=='/' || c=='*') return 2;
	return -1;
}



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    stack<char> st;
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++){
      char c = s[i];
      if(c>='A' && c<='Z') cout<<c;
      else if(c=='(') st.push(c);
      else if(c==')'){
        while(st.top()!='('){
          cout<<st.top();
          st.pop();
        }
        st.pop();
      }
      else{
        while(!st.empty() && func(st.top())>=func(c)){
          cout<<st.top();
          st.pop();
        }
        st.push(c);
      }
    }
    while(!st.empty()){
      cout<<st.top();
      st.pop();
    }
    return 0;
}

