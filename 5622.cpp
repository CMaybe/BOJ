#include <iostream>
#include<string>
using namespace std;
int arr[27] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	string s;
	cin >> s;
	for(char c : s)
		arr[26] += arr[c - 'A'];
	printf("%d", arr[26]);
	return 0;
}
