#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,cnt,dis,min = 1e9, arr[5000];
	cin >> n;

	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n-1; i++) {
		dis = arr[i + 1] - arr[i];
		if (dis < min) {
			min = dis;
			cnt = 1;
		}
		else if (dis == min) {
			cnt++;
		}
	}
	cout << min << " " << cnt;

}
