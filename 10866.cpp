#include <iostream>
#include<deque>
#include<string>
#include<cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<int> q;
	string s;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!s.compare("push_front")) {
			cin >> s;
			q.push_front(atoi(s.c_str()));
		}
		else if (!s.compare("push_back")) {
			cin >> s;
			q.push_back(atoi(s.c_str()));
		}
		else if (!s.compare("pop_front")) {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (!s.compare("pop_back")) {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << "\n";
				q.pop_back();
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
		else cout << "asfd\n";
	}

}
