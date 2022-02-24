#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct NODE
{
	int s, e, w;
}Node;

bool cmp(const Node& a, const Node& b)
{
	return a.w < b.w;
};


int arr[10001];
int ans;

int Find(int v) {
	if (v == arr[v]) return v;
	else return arr[v] = Find(arr[v]);
}

void Union(int s, int e, int weight) {
	s = Find(s);
	e = Find(e);
	if (s != e) {
		arr[s] = e;
		ans += weight;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		arr[i] = i;
	}
	vector<Node> vec;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ a,b,c });
	}
	sort(vec.begin(), vec.end(),cmp);
	for (int i = 0; i < vec.size(); i++) {
		Union(vec[i].s, vec[i].e, vec[i].w);
	}
	cout << ans;

	return 0;
}

