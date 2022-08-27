#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a + b == 0) break;
		cout << a + b << '\n';
	}
	return 0;
}
