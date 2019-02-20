#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, l, k, a;
struct position { int x, y; } pos[101];

void maybe(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (x <= pos[i].x && pos[i].x <= x + l &&
			y <= pos[i].y && pos[i].y <= y + l) cnt++;

		a = max(a, cnt);
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &l, &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &pos[i].x, &pos[i].y);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			maybe(pos[i].x, pos[j].y);
		}
	}
	printf("%d", k - a);

	return 0;
}
