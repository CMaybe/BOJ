#include <iostream>
#include <stack>


using namespace std;

int arr[1000001];
int dp[1000001];

pair<int, int> ans[1000001];
stack<int> s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int idx = 1;

	dp[idx] = arr[1];
	ans[1] = { 1,arr[1] };

	for (int i = 2; i <= n; i++) {
		if (dp[idx] < arr[i]) {
			dp[++idx] = arr[i];
			ans[i] = { idx, arr[i] };
		}
		else {
			int mid = 0;
			int s = 1, e = idx;
			while (s<e)
			{
				mid = (s + e) / 2;
				if (dp[mid] < arr[i]) s = mid + 1;
				else e = mid;
			}
			dp[e] = arr[i];
			ans[i] = { e, arr[i] };
		}
	}

	cout << idx << '\n';
	int t = idx;
	for (int i = n; i >= 1; i--) {
		if (ans[i].first == t) {
			s.push(ans[i].second);
			t--;
		}
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}
