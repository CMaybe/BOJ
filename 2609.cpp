#include <iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << (int)gcd(a, b) << "\n" << (int)lcm(a,b);
}
