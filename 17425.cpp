#include <iostream>


using namespace std;

long long int arr[1000001];
long long int arr2[1000001];

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	cin >> n;
	arr[0]=arr[1]=1;
	for(int i = 2;i<=1000000;i++){
		arr[i]+=1;
		for(int j = i;j<=1000000;j+=i){
			arr[j] += static_cast<long long int>(i);
		}
	}
	for(int i = 1;i<=1000000;i++) arr2[i] = arr[i] + arr2[i-1];
	int t;
	for(int i = 0;i<n;i++){
		cin >> t;
		cout << arr2[t] << '\n';
	}
	return 0;
	
}
