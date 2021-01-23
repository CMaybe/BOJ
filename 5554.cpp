#include<string>
#include<iostream>

using namespace std;

int main()
{
	int n, m = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int  i =0;i<4;i++){
	    cin>>n;
	    m+=n;
	}
	cout<<m/60 <<'\n'<< m%60;
}
