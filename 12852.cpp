#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int t[1000001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    arr[1] = 0;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        t[i] = i - 1;
        if (i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
            arr[i] = arr[i / 2] + 1;
            t[i] = i / 2;
        }
        if (i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
            arr[i] = arr[i / 3] + 1;
            t[i] = i / 3;
        }
    }

    cout << arr[n] << '\n';
    while (n>0)
    {
        cout << n << ' ';
        n = t[n];
    }
    return 0;
}
