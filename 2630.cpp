#include<iostream>
using namespace std;


int arr[130][130];
int c[2];

void func(int x,int y,int size)
{
	bool flag = true;
	int t = arr[y][x];
	for (int i = y; flag && i < y + size; i++) {
		for (int j = x; flag&& j < x + size; j++) {
			if (t != arr[i][j]) {
				flag = false;
			}
		}
	}
	if (flag) {
		c[t] += 1;
		return;
	}
	func(x, y, size / 2);
	func(x + size / 2, y, size/2);
	func(x , y + size / 2, size / 2);
	func(x + size / 2, y+size/2,size/2);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n,m,t,k, cnt = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			cin >> arr[i][j];
		}
	}
	func(0, 0, t);

	cout << c[0] << "\n"<< c[1];
	return 0;
}
