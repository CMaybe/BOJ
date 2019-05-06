#include <iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
int arr[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<int> st;
	string s;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!s.compare("push")) {
			cin >> s;
			st.push(atoi(s.c_str()));
		}
		else if (!s.compare("pop")) {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (!s.compare("size")) {
			cout << st.size() << "\n";
		}
		else if (!s.compare("empty")) {
			cout << st.empty() << "\n";
		}
		else if (!s.compare("top")) {
			if (st.empty()) {
				cout << "-1\n";
			}
			else cout << st.top() << "\n";
		}
	}

}
