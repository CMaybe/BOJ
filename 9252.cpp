#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

int arr[1002][1002];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	stack<char> st;
	int i = s1.length(), j = s2.length();
	while (i > 0 && j > 0) {
		if (arr[i][j] == arr[i][j - 1]) j--;
		else if (arr[i][j] == arr[i - 1][j])i--;
		else {
			i--;
			j--;
			st.push(s1[i]);
		}
	}

	cout << arr[s1.length()][s2.length()] << '\n';
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
