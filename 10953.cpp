#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a = s[0] - '0';
		b = s[2] - '0';
		cout << a + b << "\n";
	}
	return 0;
}
