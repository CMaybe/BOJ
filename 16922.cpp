#include <iostream>

using namespace std;

int NUM[4] = { 1,5,10,50 };

bool visit[10001];

int n;
int ans;

void func(int idx, int k, int t) {
	if (idx == n) {
		if (!visit[t]) {
			visit[t] = true;
			ans++;
		}
	}
	else
	{
		for (int i = k; i < 4; i++) func(idx + 1, i, t + NUM[i]);
	}
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;

	func(0, 0, 0);
	cout << ans;

	return 0;
}
