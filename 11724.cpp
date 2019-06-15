#include<cstdio>
#include<vector>
using namespace std;

vector<int> dfs[1001];
bool visit[10001];
void DFS(int n) {
	visit[n] = true;
	for (int i : dfs[n]) {
		if(!visit[i])
			DFS(i);
	}
}
int main()
{
	int m,n;
	int a, b,cnt=0;
	scanf("%d %d",&n,&m);
	while (m--)
	{
		scanf("%d %d", &a, &b);
		dfs[a].push_back(b);
		dfs[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			DFS(i);
		}
	}
	printf("%d", cnt);
}
