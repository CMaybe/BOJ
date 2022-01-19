#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct LEC {
    int n;
    int begin;
    int end;
}Lec;

bool comp(const Lec& a, const Lec& b) {
    if (a.begin == b.begin) {
        return a.end < b.end;
    }
    return a.begin < b.begin;
}


struct cmp{
    bool operator()(const Lec& a, const Lec& b) {
        if (a.end == b.end) {
            return a.begin < b.begin;
        }
        return a.end > b.end;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Lec> v(n);
    priority_queue<Lec, vector<Lec>, cmp> pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i].n >> v[i].begin >> v[i].end;
    }

    sort(v.begin(), v.end(),comp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!pq.empty()) {
            if (pq.top().end > v[i].begin) ans++;
            else pq.pop();
        }
        else ans++;

        pq.push(v[i]);
    }
    
    cout << ans;

    return 0;
}
