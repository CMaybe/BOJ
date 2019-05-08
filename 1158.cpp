#include <iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int arr[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		q.push(i);
	}
	cout << "<";

	while (!q.empty())
	{
		for (int i = 0; i < b-1; i++) {
			int t = q.front();
			q.pop();
			q.push(t);
		}
		cout << q.front();
		q.pop();
		if(!q.empty()) cout << ", ";
	}
	cout << ">";

}
