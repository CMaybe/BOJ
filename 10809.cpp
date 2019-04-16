#include<string>
#include<iostream>
using namespace std;
int arr[26];
int main()
{
	memset(arr, -1, sizeof(arr));
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (arr[s[i] - 'a'] == -1) {
				arr[s[i] - 'a'] = i;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}
