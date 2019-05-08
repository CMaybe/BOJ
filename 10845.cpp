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
	string s;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!s.compare("push")) {
			cin >> s;
			q.push(atoi(s.c_str()));
		}
		else if (!s.compare("pop")) {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (!s.compare("size")) {
			cout << q.size() << "\n";
		}
		else if (!s.compare("empty")) {
			cout << q.empty() << "\n";
		}
		else if (!s.compare("front")) {
			if (q.empty()) {
				cout << "-1\n";
			}
			else cout << q.front() << "\n";
		}
		else if (!s.compare("back")) {
			if (q.empty()) {
				cout << "-1\n";
			}
			else cout << q.back() << "\n";
		}
	}

}
