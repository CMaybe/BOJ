#include<stdio.h>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	//97 = a
	int n;
	int d=0;

	string p,dic[20];
	cin >> p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> dic[i];
		for (int j = 0; j < p.length()- dic[i].length()+1; j++) {
			bool flag = true;
			int ch = (p[j] - dic[i][0]);
			if (ch < 0) {
				ch += 26;
			}
			for (int k = 1; k < dic[i].length(); k++) {
				if (!(ch == p[j + k] - dic[i][k] || ch == (p[j + k] - dic[i][k]) + 26)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				d = ch;
				break;
			}

		}

	}
	for (int i = 0; i < p.length(); i++) {
		if (p[i] - d >= 'a')
			cout << (char)(p[i] - d);
		else
			cout << (char)(p[i] - (d-26));

	}

}
