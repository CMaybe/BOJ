#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[1000001];
int b[1000001];
 
int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
	cin >>n >>m;
    for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	
	for(int i = 1;i<=m;i++) {
		cin>>b[i];
	}
	int i_a = 1;
	int i_b = 1;
	bool flag = true;
	while(!(i_a>n && i_b>m)){
		flag = a[i_a] < b[i_b];
		if(i_a>n) flag = false;
		if(i_b>m) flag = true;
		if(flag){
			cout<<a[i_a]<<' ';
			i_a++;
		}
		else{
			cout<<b[i_b]<<' ';
			i_b++;
		}
	}
    return 0;
}
