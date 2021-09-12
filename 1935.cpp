#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;


int main() {
	int N;
    double arr[30];
    stack<double> st;
	cin >> N;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			st.push(arr[s[i] - 'A']);
		}
		else {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			if (s[i] == '*') {
				st.push(a * b);
			}
			else if (s[i] == '+') {
				st.push(a + b);
			}
			else if (s[i] == '-') {
				st.push(a - b);
			}
			else {
				st.push(a / b);
			}
		}
	}
	
	printf("%.2lf", st.top());
	return 0;
}
