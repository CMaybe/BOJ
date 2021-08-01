#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[200];

constexpr int int_pow(int b, int e)
{
    return (e == 0) ? 1 : b * int_pow(b, e - 1);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    for(int i = '0';i<='9';i++) arr[i]=i-'0';
	for(int i='A';i<='Z';i++){
		arr[i]=i-'A'+10;
	}
	string s;
	long long b;
	cin>>s>>b;
	long long sum = 0;
	for(int i = 1;i<=s.length();i++){
		int e =s.length()-i;
		sum+=arr[s[e]] * int_pow(b,i-1);
	}
	cout<<sum;
    return 0;
}

/*
19
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1
*/
