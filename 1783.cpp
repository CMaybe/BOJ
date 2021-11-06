#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;



int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	cin>>n>>m;
	if(n==1) cout<<1;
	else if(n==2)cout<<min(4,(m-1)/2+1);
	else{
		if(m>=7) cout<<m-2;
		else cout<<min(4,m);
	}
	return 0;
	
}
