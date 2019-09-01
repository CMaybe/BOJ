#include<iostream>
#include<queue>
using namespace std;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	int a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a == b) {
			cout << (a / 2) * 4 + a % 2<<"\n";
		}
		else if (a == b + 2) {
			cout << (b / 2) * 4 + a % 2 + 2 << "\n";
		}
		else {
			cout << "No Number\n";
		}
	}

}
