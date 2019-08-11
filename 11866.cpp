#include <iostream>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int cnt = 0;
	cout << "<";
	while (q.size() > 1)
	{
		int t = q.front();
		q.pop();
		if ((++cnt) % k == 0) {
			cout << t << ", ";
			continue;
		}
		q.push(t);
	}
	cout << q.front();
	cout << ">";
}
