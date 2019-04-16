#include<string>
#include<iostream>

using namespace std;
int arr[10];

int main()
{
	int n;
	string s;
	bool flag;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int sc=0,sum=0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] - 'X') {
				sc++;
				sum += sc;
			}
			else {
				sc = 0;
			}
		}
		cout << sum << "\n";
	}


}
