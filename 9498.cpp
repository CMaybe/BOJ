#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	n /= 10;
	if (n >= 9)cout << "A";
	else if (n >= 8)cout << "B";
	else if (n >= 7)cout << "C";
	else if (n >= 6)cout << "D";
	else cout << "F";
}
