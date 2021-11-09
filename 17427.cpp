#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int arr[1001][1001];

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	cin >> n;
	long long int sum=0;
	for(int i = 1;i<=n;i++) sum += static_cast<long long int>((n/i) * i);
	cout<<sum;
	return 0;
	
}
