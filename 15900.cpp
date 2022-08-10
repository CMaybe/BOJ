#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int ans;
bool visit[500001];
vector<int> v[500001];

void dfs(int node, int depth)
{
	if (node != 1 && v[node].size() == 1) 
	{
		if (depth % 2 == 1) ans++;
		return;
	}

	for (int next : v[node])
	{
		if (visit[node]) continue;
		visit[node] = true;
		dfs(next, depth + 1);
		visit[node] = false;

	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}


	dfs(1, 0);

	if (ans % 2 == 1) cout << "Yes";
	else cout << "No";

}
