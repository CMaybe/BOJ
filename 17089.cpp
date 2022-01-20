#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[4001];
bool graph[4001][4001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 1e9;
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a]++;
        arr[b]++;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (graph[i][j]) {
                for (int k = j + 1; k <= n; k++) {
                    if (graph[k][j] && graph[k][i]) {
                        int t = arr[i] + arr[j] + arr[k] - 6;
                        ans = min(t, ans);
                    }
                }
            }
        }
    }

    cout << ((ans == 1e9) ? -1 : ans);

    return 0;
}
