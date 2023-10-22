#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[1001];
bool visited[1001] = { false, };

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({ dst, cost });
        edge[dst].push_back({ src, cost });
    }
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int result = 0;
    pq.push({ 0, 1 });
    for (int i = 1; i <= N; i++) {
        while (!pq.empty() && visited[pq.top().second]) {
            pq.pop();
        }
        int next = pq.top().second;
        int minCost = pq.top().first;
        visited[next] = true;
        result += minCost;
        for (auto i : edge[next]) {
            pq.push({ i.second, i.first });
        }
    }
    cout << result << '\n';
}
