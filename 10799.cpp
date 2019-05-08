#include<iostream>
#include<stack>
#include<string>
using namespace std;
int arr[1000001];
int main()
{
	int cnt=0,t = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<char> st;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			t++;
			st.push('(');
		}
		else {
			if (st.top() == '(') {
				t--;
				cnt += t;
			}
			else {
				cnt += 1;
				t -= 1;
			}
			st.push(')');

		}
	}
	cout << cnt;

}
