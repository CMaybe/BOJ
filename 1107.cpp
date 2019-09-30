#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
vector<int> v;

bool func(int n)
{
	do{
		if (find(v.begin(), v.end(), n % 10) != v.end()) {
			return false;
		}
		n/=10;
	} while (n);
	return true;
}
int main() {
	int n,t,c,ans;
	cin >> n;
	cin >> t;
	while (t--)
	{
		cin >> c;
		v.push_back(c);
	}
	ans = abs(n - 100);
	if (ans <= 1) {
		cout << ans;
		return 0;
	}
	for (int i = 0; i <= 1000000; i++) {
		if (func(i)) {
			if (ans <= 1) {
				cout << ans;
				return 0;
			}
			int tmp = to_string(i).length();
			tmp += abs(i - n);
			ans = ans < tmp ? ans : tmp;
		}
	}
	cout << ans;
	return 0;

}
