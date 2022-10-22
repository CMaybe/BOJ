#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool flag = true;
	string A, T, A_rev;
	string left = "", right = "";
	cin >> A >> T;
	A_rev = A;
	reverse(A_rev.begin(), A_rev.end());
	deque<char> dq(T.begin(), T.end());
	while (true) {
		while (true) {
			if (left.length() >= A.length() && left.substr(left.length() - A.length(),A.length()) == A) {
				for (int i = 0; i < A.length(); i++)left.pop_back();
				break;

			}
			if (!dq.empty()) {
				left.push_back(dq.front());
				dq.pop_front();
			}
			else if (!right.empty()) {
				left.push_back(right.back());
				right.pop_back();
			}
			else {
				flag = false;
				break;
			}
		}
		if (!flag) break;

		while (true) {
			if (right.length() >= A.length() && right.substr(right.length() - A.length(), A.length()) == A_rev) {
				for (int i = 0; i < A.length(); i++)right.pop_back();
				break;

			}
			if (!dq.empty()) {
				right.push_back(dq.back());
				dq.pop_back();
			}
			else if (!left.empty()) {
				right.push_back(left.back());
				left.pop_back();
			}
			else {
				flag = false;
				break;
			}
		}
		if (!flag) break;

	}

	reverse(right.begin(), right.end());
	cout << left << right;

	return 0;
}
