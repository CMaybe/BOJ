#include <iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<int> st;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int sum = 0;
	int k,t;
	cin >> k;
	while (k--)
	{
		cin >> t;
		if (t == 0) {
			st.pop();
			continue;
		}
		st.push(t);
	}
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
}
