#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int arr[4001];
bool graph[4001][4001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    map<string, int, greater<string>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if ("enter" == b) m[a] = 1;
        else if ("leave" == b)m[a] = 0;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == 1) cout << iter->first << '\n';
    }

    return 0;
}
