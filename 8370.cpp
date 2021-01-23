#include<string>
#include<iostream>

using namespace std;

int main()
{
	int n, m,s = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	s+=n*m;
	cin>>n>>m;
	s+=n*m;
	cout<<s;
}
