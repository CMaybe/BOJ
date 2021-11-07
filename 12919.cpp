#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>

using namespace std;
int flag = 0;

void func(string t, const string& s){
	if(flag==1)return;
	if(s.length()>t.length()) return;
	if(s==t){
		flag = 1;
		return;
	}
	if(t[t.length()-1]=='A') func(t.substr(0,t.length()-1),s);
	if(t[0]=='B'){
		string temp = t;
		reverse(temp.begin(), temp.end());
		func(temp.substr(0,temp.length()-1),s);
	}
	return;
}

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	string s, t;
	cin >> s>> t;
	if(t[t.length()-1]=='A') func(t.substr(0,t.length()-1),s);
	if(flag==1){ }
	if(t[0]=='B'){
		string temp = t;
		reverse(temp.begin(), temp.end());
		func(temp.substr(0,temp.length()-1),s);
	}
	cout<<flag;
	return 0;
	
}
