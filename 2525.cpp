#include<iostream>

int main() {
	int a, b, c;

	std::cin >> a >> b >> c;
	int ans = a * 60 + b + c;
	std::cout << (ans / 60) % 24<<' ' << ans % 60;

}
