#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[52][52];
int arr2[52][52];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

typedef struct NODE {
	int x;
	int y;
}Node;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 51; j++) {
			arr[i][j] = -1;
		}
	}
	int r, c, t, y1 = -1, y2;
	cin >> r >> c >> t;
	vector<Node> v;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) v.push_back({ j,i });
			if (arr[i][j] == -1) {
				if (y1 == -1) y1 = i;
				else y2 = i;
			}

		}
	}
	while (t--) {
		memset(arr2, 0, sizeof(arr2));

		for(Node node : v) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				if (arr[ny][nx] == -1) continue;
				cnt++;
				arr2[ny][nx] += (arr[node.y][node.x] / 5);
			}
			arr2[node.y][node.x] += -(arr[node.y][node.x] / 5 * cnt);
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) arr[i][j] += arr2[i][j];
		}


		for (int i = y1 - 1; i >= 2; i--) arr[i][1] = arr[i - 1][1];
		for (int i = 1; i < c; i++) arr[1][i] = arr[1][i + 1];
		for (int i = 1; i <= y1; i++) arr[i][c] = arr[i + 1][c];
		for (int i = c; i > 2; i--) arr[y1][i] = arr[y1][i - 1];


		for (int i = y2 + 1; i < r; i++) arr[i][1] = arr[i + 1][1];
		for (int i = 1; i < c; i++) arr[r][i] = arr[r][i + 1];
		for (int i = r; i > y2; i--) arr[i][c] = arr[i - 1][c];
		for (int i = c; i > 1; i--) arr[y2][i] = arr[y2][i - 1];


		arr[y1][2] = 0;
		arr[y2][2] = 0;
		v.clear();
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (arr[i][j] > 0) v.push_back({ j,i });
			}
		}
	}

	int sum = 2;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			sum += arr[i][j];
		}
	}

	cout << sum;
	return 0;
}
