#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt = 0;
	while((m+n > k) && m>=1 && n>=2){
		cnt++;
		n-=2;
		m-=1;
	}
	if(n+m>=k) cout << cnt;
	else cout << cnt -1;
	return 0;
	
}
