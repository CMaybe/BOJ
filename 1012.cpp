#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;


int arr[52][52];
bool visit[52][52];

void DFS(int j, int i)
{
	if (visit[i][j]) return;
	visit[i][j] = true;
	if (arr[i - 1][j]) {
		DFS(j,i - 1);
	}
	if (arr[i + 1][j]) {
		DFS(j,i + 1);
	}
	if (arr[i][j - 1]) {
		DFS(j - 1,i);
	}
	if (arr[i][j + 1]) {
		DFS(j + 1,i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n,m,t,k, cnt = 0;
	cin >> t;
	while (t--)
	{
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		cin >>m>>n>> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			arr[y + 1][x + 1] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] && !visit[i][j]) {
					DFS(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;
	}


	return 0;
}
