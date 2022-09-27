#include <iostream>
#include <cmath>

using namespace std;
long long arr[100001];
int main(int argc, char* argv[]) {
	int n;
	long long ans1,ans2;
	cin >> n;  
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
	}
	
	long long sum =  2000000001;
	
	for(int i = 1;i<n;i++){
		long long t1 = arr[i];
		long long t2 = arr[n];
		int s = i+1;
		int e = n;
		while(s<=e){
			int mid = (s + e)/2;
			t2 = arr[mid];
			if(t1 + t2 == 0) {
			    sum = t1+t2;
			    ans1 = t1;
			    ans2 = t2;
				break;
			}
			else if(t1 + t2 > 0){
				e = mid-1;
			}
			else if(t1 + t2 < 0){
				s = mid+1;
			}
			if(abs(t1+t2) < abs(sum)){
			    sum = t1+t2;
			    ans1 = t1;
			    ans2 = t2;
		    }
		}
	
		
	}
	
	cout << ans1 <<' '<< ans2;
	
	return 0;
}
