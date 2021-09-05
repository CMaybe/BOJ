#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	string s;
	vector<string> v;
	cin>>s;
	for(int i = 0;i<s.length();i++){
		v.push_back(s.substr(i,s.length()-i));
	}
	sort(v.begin(),v.end());
	for(string c : v)
		cout<<c<<'\n';
	return 0;
	
}
