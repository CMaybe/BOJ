#include <iostream>
using namespace std;


int main() {

	int n,m,a;

	cin >> n >> m >> a;
	a--;
	while (1) {
		int t;
		cin >> t;
		if (t == m / 2 + 1) {
			cout << 0;
			break;
		}
		a = (n + a + t - (m / 2) - 1) % n;
		cout<<a+1<<"\n";
	}

}
