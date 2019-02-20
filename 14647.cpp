#include<cstdio>
#include<string>

using namespace std;
int garo[500];
int sero[500];
int sTem;
int nine;
int main()
{
	int max = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int tem = 0;
		for (int j = 0; j < m; j++) {
			int num;
			scanf("%d", &num);
			string temp = to_string(num);
			sTem = 0;
			for (int k = 0; k < temp.length(); k++) {
				if (temp[k] == '9')
				{
					tem++;
					sTem++;
				}
			}
			sero[j] += sTem;
		}
		garo[i] = tem;
		nine += tem;
		if (max < garo[i]) {
			max = garo[i];
		}
	}
	for (int i = 0; i < m; i++) {
		if (max < sero[i])
		{
			max = sero[i];

		}
	}
	printf("%d", nine - max);
}
