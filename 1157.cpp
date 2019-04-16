#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int arr[26];
int main()
{
	int n,max=0;
	bool flag = false;
	int t;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[toupper(s[i]) - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			t = i;
			max = arr[i];
		}
	}
	for (int i = 0; i < 26; i++) {
		if (i == t)continue;
		if (max == arr[i]) {
			cout << "?";
			return 0;
		}
	}
	cout << (char)(t+'A');
}
