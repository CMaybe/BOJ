#include<iostream>
#include<string>

using namespace std;
string s[51];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int size = s[0].length();
	for (int i = 0; i < size; i++) {
		char t = s[0][i];
		for (int j = 1; j < n; j++) {
			if (t != s[j][i]) s[0][i] = '?';
		}
	}
	cout << s[0];

}
