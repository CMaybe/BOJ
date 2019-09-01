#include<cstdio>
int main()
{
	int x, y, w, h;
	int min = 1e9;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if (w / 2 < x) {
		min = w - x;
	}
	else min = x;
	if (h / 2 < y) {
		min = min < (h - y) ? min : h - y;
	}
	else {
		min = min < y ? min : y;
	}
	printf("%d", min);

}
