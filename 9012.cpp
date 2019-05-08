#include<iostream>
#include<stack>
#include<string>
using namespace std;
int arr[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<char> st;
	string s;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') st.push('(');
			else {
				if (st.empty() || st.top() == ')') {
					st.push(')');
					break;
				}
				if (st.top() == '(') {
					st.pop();
				}
			}
		}
		if (st.empty()) cout << "YES\n";
		else cout << "NO\n";
		while (!st.empty())st.pop();
	}

}
