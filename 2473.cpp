#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long int;
ll arr[5001];
int ans[3];
int main(int argc, char* argv[]) {
    cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;  
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	
	ll sum =  3000000001;
	for(int i = 0;i<n-2;i++){
		int s = i+1;
		int e = n-1;
		while(s<e){
			ll t = arr[i] + arr[s] + arr[e];
            // cout <<arr[i] << '\t'<<arr[s] << '\t'<<arr[e] << '\t'<< t << '\n';
			if(abs(sum) > abs(t)){
			    sum = t;
			    ans[0] = arr[i];
			    ans[1] = arr[s];
			    ans[2] = arr[e];
			}
			if(t >=0 ) e--;
			else s++;
		}
	}
	for(int i = 0; i < 3; i++) cout << ans[i] << ' ';
	return 0;
}
