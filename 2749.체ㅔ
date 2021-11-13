#include <iostream>
using namespace std;

int arr[1500001];
// 피사노 주기
int main()
{
	long long int n;
	cin >>n;
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2;i<=1500000;i++) arr[i] = (arr[i-1] + arr[i-2]) % 1000000;
	cout << arr[n%1500000];
	return 0;
	
}
