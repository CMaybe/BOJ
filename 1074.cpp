#include<cstdio>
#include<cmath>

int gr, gc, cnt;
void func(int n, int r, int c)
{
	if (n == 2) {
		if (r == gr && c == gc) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (r == gr && c + 1 == gc) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (r+1 == gr && c == gc) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (r+1 == gr && c + 1 == gc) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		return;
	}
	func(n / 2, r, c);
	func(n / 2, r, c + n / 2);
	func(n / 2, r + n / 2, c);
	func(n / 2, r + n / 2, c + n / 2);
}

int main()
{
	int size;
	scanf("%d %d %d", &size, &gr, &gc);
	func(pow(2, size), 0, 0);
}
