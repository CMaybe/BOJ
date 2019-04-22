#include<cstdio>
#include<string>
#include<cmath>
#include<vector>

using namespace std;
void hanoi(int n, int s, int m, int e) {
	if (n == 1) {
		printf("%d %d\n", s, e);
		return;
	}
	hanoi(n - 1, s, e, m);
	printf("%d %d\n", s, e);
	hanoi(n - 1, m, s, e);
}

int main()
{
	int n;
	scanf("%d", &n);
	string s = to_string(pow(2, n));
	s = s.substr(0, s.find('.'));
	s[s.length() - 1] -= 1;
	printf("%s", s.c_str());
	printf("\n");
	if (n <= 20)hanoi(n, 1, 2, 3);
	return 0;
}
