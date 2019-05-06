#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct POINT {
	int x;
	int y;
}Point;

vector<Point> v[26][26];
stack<Point> st;
int result[10001];
int arr[27][27];
bool visit[27][27];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i - 1][j]) {
				v[i][j].push_back(Point{ j,i - 1 });
			}
			if (arr[i + 1][j]) {
				v[i][j].push_back(Point{ j,i + 1 });
			}
			if (arr[i][j - 1]) {
				v[i][j].push_back(Point{ j - 1,i });
			}
			if (arr[i][j + 1]) {
				v[i][j].push_back(Point{ j + 1,i });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] && !visit[i][j]) {
				st.push(Point{ j,i });
				visit[i][j] = true;
				int ct = 1;
				while (!st.empty())
				{
					Point p = st.top();
					if (v[p.y][p.x].empty()) {
						st.pop();
					}
					else {
						while (true)
						{

							Point t = v[p.y][p.x].back();
							if (visit[t.y][t.x]) {
								v[p.y][p.x].pop_back();
								if (v[p.y][p.x].empty())
								{
									st.pop();
									break;
								}
							}
							else {
								ct++;
								st.push(t);
								visit[t.y][t.x] = true;
								v[p.y][p.x].pop_back();
								break;
							}
						}
					}
				}
				result[cnt++] = ct;
			}
		}
	}
	cout << cnt << "\n";
	sort(result, result + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
