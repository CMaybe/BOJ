#include<cstdio>

int a[300];
int b[300];

//가위를 1, 바위를 2, 보를 3
int si(int a, int b) {
	if (a == b) return 0;
	if (a - b == -1 || a - b == 2)
		return 2;
	return 1;
}

int main()
{
	int max = -10;
	int temp = 0;
	bool flag = true; // true : a, false : b;
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &b[0]);
	flag = !(si(a[0],b[0])-1);
	temp++;
	for (int i = 1; i < n; i++) {
		scanf("%d", &b[i]);
		if (si(a[i],b[i]) == 1)
		{
			if (flag)
				temp++;
			else
			{
				flag = !flag;
				max = max > temp ? max : temp;
				temp = 1;
			}
		}
		else if (si(a[i], b[i])==2)
		{
			if (!flag)
				temp++;
			else {
				flag = !flag;
				max = max > temp ? max : temp;
				temp = 1;
			}
		}
		else {
			max = max > temp ? max : temp;
			temp = 1;
			flag = !flag;
		}
	}
	max = max > temp ? max : temp;
	printf("%d", max);
}
