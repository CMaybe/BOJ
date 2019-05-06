#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;


int result[10001];
int arr[27][27];
bool visit[27][27];
int ct;

void DFS(int j, int i)
{
	if (visit[i][j]) return;
	visit[i][j] = true;
	ct++;
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
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] && !visit[i][j]) {
				DFS(j, i);
				result[cnt++] = ct;
				ct = 0;
			}
		}
	}
	cout << cnt << "\n";
	sort(result, result + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
