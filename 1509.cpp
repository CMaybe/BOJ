#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int dp[2501];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	cin >> s;
	dp[0] = 1;
	for (int i = 1; i <= s.length(); i++)dp[i] = 1e9;
	for (int i = 0; i < s.length(); i++) {
		dp[i] = min(dp[i], dp[i - 1] + 1);
		int j = 1;
		while (i - j >= 0 && i + j < s.length()) {
			if (s[i - j] != s[i + j]) break;
			dp[i + j] = min(dp[i + j], dp[i - j - 1] + 1);
			j++;
		}
		j = 1;
		while (i - j + 1 >= 0 && i + j < s.length()) {
			if (s[i - j + 1] != s[i + j]) break;
			dp[i + j] = min(dp[i + j], dp[i - j] + 1);
			j++;
		}
	}
	cout << dp[s.length() - 1];
	return 0;
}
