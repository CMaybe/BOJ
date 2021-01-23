#include <iostream>
using namespace std;
int a[1001], b[1001];
int main() {
    int n=0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
    	cin>>a[i];
    	b[i]=1e9;
		for (int j = 1; j <= i; j++)
		{
			if (b[i] > b[i - j] + a[j])
				b[i] = b[i - j] + a[j];
		}
	}
	cout<< b[n];
	return 0;
}
