#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	cout << s[0];
	for(int i = 1;i<s.length();i++){
		if (i % 10 == 0)printf("\n");
		cout << s[i];
	}
}
