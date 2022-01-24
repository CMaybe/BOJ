#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int root[1000001];

int Find(int node) {
    if (node == root[node]) return node;
    root[node] = Find(root[node]);
    return root[node];
}

void Union(int a, int b) {
    int fa = Find(a);
    int fb = Find(b);

    if (fa < fb) root[fb] = fa;
    else root[fa] = fb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i <= 1000000; i++) root[i] = i;

    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            Union(a, b);
        }
        else {
            int t1 = Find(a);
            int t2 = Find(b);
            if (t1 == t2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
