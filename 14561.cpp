#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s[30];
	bool flag = true;
	long long int n, t1, t2, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		s->clear();
		cnt = 0;
		cin >> t1 >> t2;
		do
		{
			s[cnt++] = to_string(t1 % t2);
			t1 /= t2;
		} while (t1 > 0);
		cnt--;
		int c = 0;
		flag = true;
		while (c <= cnt/2)
		{
			if (s[c]!=s[cnt - c]) {
				flag = false;
				break;
			}
			c++;
		}
		if (flag) cout << "1\n";
		else cout << "0\n";

		cnt = 0;
	}
	return 0;
}
