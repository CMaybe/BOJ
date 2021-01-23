#include <iostream>
#include<vector>
using namespace std;
int arr[1001];
int d[1001];
vector<int> v[1001];
int maxIdx= 1;
int main() {
    int n=0,max=1;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		cin>>arr[i];
		v[i].push_back(arr[i]);
		for (int j = i; j >= 1; j--) {
			if (arr[i] > arr[j] &&(d[j] > d[i]-1)) {
				d[i] = d[j] + 1;
				v[i]=v[j];
				v[i].push_back(arr[i]);
				if (max < d[i]) {
					max = d[i];
					maxIdx=i;
				}
			}
		}
	}
	cout<<max<<'\n';
    for(int i =0;i<v[maxIdx].size();i++){
        cout<<v[maxIdx].at(i)<<' ';
    }
	return 0;
}
