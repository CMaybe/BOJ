#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX 1001

bool visit[MAX];
vector<int> arr[MAX];
queue<int> q;


void DFS(int x)
{
	visit[x] = true;
	printf("%d ", x);
	for (int i : arr[x]) {
		if (!visit[i]) {
			DFS(i);
		}
	}
}

void BFS(int s) {
	q.push(s);
	visit[s] = true;
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		printf("%d ", i);
		for (int j : arr[i]) {
			if (!visit[j]) {
				q.push(j);
				visit[j] = true;
			}
		}
	}
}

int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	for (int i = 1; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	DFS(v);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(v);

}