#include <iostream>
using namespace std;

int arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;
    cout << arr[n];

    return 0;
}
