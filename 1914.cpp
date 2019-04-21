#include<cstdio>
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
	int n, t = 0;
	vector<int> v;
	scanf("%d", &n);
	v.push_back(1);
	for (int i = 1; i <= n; i++) {
		v.push_back(0);
		for (int j =0; j <v.size(); j++) {

			v[j] = v[j] + v[j] + t;
			if (v[j] >= 10) {
				v[j] %= 10;
				t = 1;
			}
			else t = 0;

		}
	}
	bool flag = false;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == 0 && !flag) continue;
		flag = true;
		if (i == 0) {
			printf("%d", v[i] - 1);
			break;
		}
		printf("%d", v[i]);
	}
	printf("\n");
	if(n<=20)hanoi(n, 1, 2, 3);
	return 0;
}
