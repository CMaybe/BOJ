#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (c * 2 <= a+b) {
		if (a >= 2 * c && b >= 2 * c) cout << 2 * c * max(x, y);
		else if (x <= y) {
			if (2 * c <= b) cout << 2 * c * y;
			else cout << 2 * c * x + (y - x) * b;
		}
		else if (y < x) {
			if (2 * c <= a) cout << 2 * c * x;
			else cout << 2 * c * y + (x - y) * a;
		}
	}
	else
	{
		cout << a * x + b * y;
	}
	
	
	return 0;

}
