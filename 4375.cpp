#include<iostream>
using namespace std;
int main()
{
	long long int n;
	while (cin>>n)
	{
		if (n == 1) {
			cout<<"1\n";
			continue;
		}
		int cnt = 1;
		long long int num = 1;
		while ((num = (num * 10) % n + 1)%n)
		{
			cnt++;
		}
		cout << cnt+1<<"\n";
	}

}
