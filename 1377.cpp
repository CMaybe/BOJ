#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

pair<int ,int> arr[500001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	int n;
	int ans = -1;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	
	
	for(int i=0;i<n;i++){
		ans = max(ans, arr[i].second - i);
	}
	cout<<ans + 1;
	
	return 0;
	
}
