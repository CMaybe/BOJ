#include<iostream>
#include<string>
using namespace std;
long double arr[10001] = { 0,1 };
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	string s = to_string(arr[n]);
	s = s.substr(0, s.find('.'));
	cout << s;
}
