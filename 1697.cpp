#include<cstdio>
#include<string>
#include<queue>
using namespace std;

vector<int> bfs[100001];
int v[100001];
queue<int> q;
int main()
{
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	if (n == k) {
		printf("0");
		return 0;
	}
	q.push(n);
	v[n] = 0;
	v[k] = 1e9;
	if (n * 2 <= 100000 && n!=0) bfs[n].push_back(n * 2);
	if (n - 1 >= 0)bfs[n].push_back(n - 1);
	if (n + 1 <= 100000)bfs[n].push_back(n + 1);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (v[t] > v[k])continue;
		if (t * 2 <= 100000 && t!=0) bfs[t].push_back(t * 2);
		if (t - 1 >= 0)bfs[t].push_back(t - 1);
		if (t + 1 <= 100000)bfs[t].push_back(t + 1);
		for (int i : bfs[t]) {
			if (v[i] == 0) {
				q.push(i);
				v[i] = v[t] + 1;
			}
			else if (v[i]> v[t] + 1) {
				v[i] = v[t] + 1;
				q.push(i);
			}
		}
	}
	printf("%d", v[k]);
}