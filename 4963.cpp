
#include<iostream>
#include<cstring>
using namespace std;

int arr[52][52];
int ax[8] = { 1,1,1,-1,-1,-1,0,0 };
int ay[8] = { 1,-1,0,1,0,-1,-1,+1 };

void DFS(int y, int x)
{
	arr[y][x] = 0;
	for (int i = 0; i < 8; i++) {
		if (arr[y + ay[i]][x + ax[i]])
			DFS(y + ay[i], x + ax[i]);
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, cnt = 0;
	do
	{

		cnt = 0;
		memset(arr, 0, sizeof(arr));
		cin >> a >> b;
		if (!(a || b))break;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				cin >> arr[i+1][j+1];
			}
		}

		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= a; j++) {
				if (arr[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	} while (true);
}
