#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int arr[26];
int main()
{
	int n, cnt = 0;
	string s;
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		memset(arr, -1, sizeof(arr));
		cin >> s;
		flag = true;
		for (int j = 0; j < s.length(); j++) {
			if (arr[s[j] - 'a'] == -1)arr[s[j] - 'a'] = j;
			else
			{
				if ((j - arr[s[j] - 'a']) != 1) {
					flag = false;
					break;
				}
				arr[s[j] - 'a'] = j;
			}
		}
		if (flag)cnt++;
	}
	cout << cnt;
}
