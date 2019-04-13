#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end(),desc);
	cout << s;
}
