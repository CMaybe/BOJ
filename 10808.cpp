#include<iostream>
#include<string>
using namespace std;

	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int arr[26] = {0,};
	string s;
	cin>>s;
	for(int i = 0;i<s.length();i++){
		arr[static_cast<int>(s[i]) - 97]++;
	}
	for(int i = 0;i<26;i++){
		cout<<arr[i]<<' ';
	}
	return 0;
	
}
