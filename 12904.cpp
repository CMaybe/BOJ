#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int able = 0;
string s ,t;



int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	cin>>s>>t;
	while(s!=t){
		if(t.length()==0){
			cout<<0;
			return 0;
		}
		if(t[t.length()-1]=='A'){
			t= t.substr(0, t.length()-1);
		}
		else if(t[t.length()-1]=='B'){
			t= t.substr(0, t.length()-1);
			reverse(t.begin(),t.end());
		}
		else{
			cout<<0;
			return 0;
		}
	}
	
	cout << 1;
	return 0;
	
}
