#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	string s1, s2, ans;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 0; i < len1; i++) {
		ans += s1[i];
		bool flag = true;
		if (s1[i] == s2.back() && ans.length() >= len2) {
			for (int j = 0; j < len2; j++) {
				if (s2[j] != ans[ans.length() - len2 + j]) {
					flag = false;
					break;
				}
			}
			if (flag) ans.erase(ans.length() - len2, len2);
		}
	}
	if (ans.length() == 0) cout << "FRULA";
	else cout << ans;


	return 0;
}
