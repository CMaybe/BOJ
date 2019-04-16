#include<cstdio>
#include<string>
using namespace std;
int arr[10];

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	c *= a * b;
	string s = to_string(c);
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

}
