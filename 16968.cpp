#include <iostream>
#include <string>
using namespace std;


int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	string s;
	cin >> s;
	int ans = 0;
	if (s[0] == 'd') ans = 10;
	else ans = 26;
	for (int i = 1; i < s.length(); i++) {
		int t = 0;
		if (s[i] == 'd') t = 10;
		else t = 26;
		if (s[i] == s[i - 1]) t--;
		ans *= t;
	}
	cout << ans;
	
	
	return 0;

}
