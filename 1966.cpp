#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

vector<int> q;
vector<int> idx;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n,a,b,c;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		q.clear();
		idx.clear();
		for (int i = 0; i < a; i++) {
			cin >> c;
			q.push_back(c);
			idx.push_back(i);
		}
		int cnt = 0;
		while (!q.empty())
		{
			int t1 = q.front();
			q.erase(q.begin());
			int t2 = idx.front();
			idx.erase(idx.begin());
			bool flag = true;
			for (int i : q) {
				if (t1 < i) {
					flag = false;
					q.push_back(t1);
					idx.push_back(t2);
					break;
				}
			}
			if (flag) {
				cnt++;
				if (b == t2) {
					cout << cnt << "\n";
					break;
				}
			}
		}
	}


}
