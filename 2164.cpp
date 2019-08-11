#include <iostream>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size()!=1)
	{
		q.pop();
		int t = q.front();
		q.push(t);
		q.pop();
	}
	cout << q.front();

}
