#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>

using namespace std;

int arr1[100003];
int arr2[100003];
int ans[100003];

int main()
{
	
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(0);
	int n, _min = 1e9;
	scanf("%d",&n);
	
	for(int i = 1;i<=n;i++){
		scanf("%1d",&arr1[i]);
		arr2[i] = arr1[i];
	}
	
	arr2[1] ^= 1;
	arr2[2] ^= 1;
	
	for(int i = 1;i<=n;i++){
		scanf("%1d",&ans[i]);
	
	}
	
	int cnt1=0,cnt2=1;
	for(int i = 1;i<n;i++){
		if(arr1[i]!=ans[i]){
			cnt1++;
			arr1[i] ^= 1;
			arr1[i+1] ^= 1;
			arr1[i+2] ^= 1;
		}
		if(arr2[i]!=ans[i]){
			cnt2++;
			arr2[i] ^= 1;
			arr2[i+1] ^= 1;
			arr2[i+2] ^= 1;
		}
	}

	bool flag1 = true;
	bool flag2 = true;
	
	for(int i = 1;i<=n;i++){
		if(arr1[i] != ans[i]){
			flag1 = false;
			break;
		}
	}
	if(flag1) _min = cnt1;
	for(int i = 1;i<=n;i++){
		if(arr2[i] != ans[i]){
			flag2 = false;
			break;
		}
	}
	if(flag2) _min = min(_min, cnt2);
	if(flag1 || flag2) printf("%d", _min);
	else printf("-1");
	
	return 0;
	
}
