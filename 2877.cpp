#include<cstdio>
#include<stack>

using namespace std;

int main()
{
	int n;
	stack<int> s;
	scanf("%d", &n);
	n += 1;
	do
	{
		s.push(n % 2);
		n /= 2;
	} while (n > 0);
	s.pop();
	while (!s.empty())
	{
		int t = s.top();
		s.pop();
		if (t == 0)printf("4");
		else printf("7");
	}
	return 0;
}
