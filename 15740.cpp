
#include <iostream>
#include<string>
#include<stack>

using namespace std;
int main()
{
	string as, bs;
	bool am = false, bm = false;
	bool zflag = true;
	stack<char> a, b;
	stack<int> sum;
	int tmp, up=0;
	cin >> as >> bs;

	if (as[0] == '-') {
		am = true;
		as = as.substr(1, as.length() - 1);
	}
	if (bs[0] == '-') {
		bm = true;
		bs = bs.substr(1, bs.length() - 1);
	}
	for (int i = 0; i < as.length(); i++) {
		a.push(as[i]);
	}
	for (int i = 0; i < bs.length(); i++) {
		b.push(bs[i]);
	}
	// ++ --
	if (a.size()<b.size()) {
		if (bm)printf("-");
		a.swap(b);
	}
	else if (a.size() == b.size()) {
		int i = 0;
		for (i= 0; i < a.size(); i++) {
			if (as[i] - bs[i] > 0) {
				if (am) printf("-");
				break;
			}
			else if (as[i] - bs[i] < 0) {
				a.swap(b);
				if (bm)printf("-");
				break;
			}
		}
	}
	else if (am)printf("-");
	if (am^bm) {
		do
		{
			int c, d;
			if (a.empty()) {
				c = 0;
			}
			else {
				c = a.top() - '0';
			}
			if (b.empty()) {
				d = 0;
			}
			else {
				d = b.top() - '0';
			}
			tmp = c - d + up;
			if (tmp < 0) {
				sum.push((tmp+10) % 10);
				up = -1;
			}
			else {
				up = 0;
				sum.push(tmp);
			}
			if (!a.empty())a.pop();
			if (!b.empty())b.pop();

		} while (!(b.empty() && a.empty()));
	}
	else {
		do
		{
			int c, d;
			if (a.empty()) {
				c = 0;
			}
			else {
				c = a.top() - '0';
			}
			if (b.empty()) {
				d = 0;
			}
			else {
				d = b.top() - '0';
			}
			tmp = c + d + up;
			if (tmp >= 10) {
				sum.push(tmp % 10);
				up = 1;
			}
			else {
				up = 0;
				sum.push(tmp);
			}
			if (!a.empty())a.pop();
			if (!b.empty())b.pop();

		} while (!(b.empty() && a.empty()));
		if (up) {
			printf("1");
			zflag = false;
		}
	}

	while (!sum.empty()) {
		if (!sum.top() && zflag) {
			sum.pop();
			continue;
		}
		zflag = false;
		printf("%d", sum.top());
		sum.pop();
	}
	if (zflag)printf("0");
}
