#include <iostream>

using namespace std;

int gcd(int a, int b){
	int r = a % b;
	if (r == 0)
		return b;
	else
		return gcd(b, r);
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >>n;
    	long long sum=0;
    	int arr[101]={0,};
		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}
		for(int i =0;i<n-1;i++){
			for(int j =i+1;j<n;j++){
				sum+=gcd(arr[i],arr[j]);
			}
		}
		cout<<sum<<'\n';
    }
}


