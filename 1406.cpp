#include<iostream>
#include<stack>
#include<string>
using namespace std;
int arr[1000001];
int main()
{
	int n;
	char t;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<char> f,b,r;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		f.push(s[i]);
	}
	cin >> n;
	while (n--)
	{
		cin >> t;
		switch (t)
		{
		case 'P':
			cin >> t;
			f.push(t);
			break;
		case 'L':
			if (f.empty()) break;
			t = f.top();
			f.pop();
			b.push(t);
			break;
		case 'B':
			if (f.empty()) break;
			f.pop();
			break;
		case 'D':
			if (b.empty()) break;
			t = b.top();
			b.pop();
			f.push(t);
			break;
		default:
			break;
		}

	}
	while (!f.empty())
	{
		r.push(f.top());
		f.pop();
	}
	while (!r.empty())
	{
		cout << r.top();
		r.pop();
	}
	while (!b.empty())
	{
		cout << b.top();
		b.pop();
	}

}
