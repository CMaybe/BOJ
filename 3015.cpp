#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct NODE {
    unsigned int height;
    int cnt;
}Node;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    stack<Node> st;
    vector<Node> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].height;
        v[i].cnt = 1;
    }
    long long ans = 0;
    for (int i = 0; i < n;) {
        if (st.empty()) {
            st.push(v[i]);
            i++;
        }
        else{
            if (st.top().height > v[i].height) {
                ans++;
                st.push(v[i]);
                i++;
            }
            else if (st.top().height == v[i].height) {
                v[i].cnt += st.top().cnt;
                ans += st.top().cnt;
                st.pop();
            }
            else {
                ans += st.top().cnt;
                st.pop();
            }
        }
    }

    cout << ans;

    return 0;
}
