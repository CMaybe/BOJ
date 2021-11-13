#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int len(int n){
	int l = 0;
	for(int s = 1,i=1;s<=n;s*=10,i++){
		int e = s*10 - 1;
		if (e>n)e = n;
		l+=((e-s)+1)*i;
	}
	return l;
}

int main()
{
	int n, k;
	cin >> n >> k;
	if(len(n) < k){
		cout << -1;
		return 0;
	}
	int pos=0;
	int s=1, e=n;
	while(s<=e){
		int mid = (s+e)/2;
		if(len(mid) < k) s = mid + 1;
		else pos=mid,e=mid-1;
	}
	int c = len(pos);
	string str = to_string(pos);
	cout<<str[str.length()-1-(c-k)];
	return 0;
	
}
