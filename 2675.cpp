#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int arr[26];
int main()
{
	int n;
	string s;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t >> s;

		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < t; k++) {
				cout << s[j];
			}
		}
		cout << "\n";
	}
}
