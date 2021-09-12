#include<iostream>
#include<string>
using namespace std;

	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int a,b,c,d;
    cin>>a>>b>>c>>d;
    string s1,s2;
    s1 = to_string(a)+to_string(b);
    s2 = to_string(c)+to_string(d);
    cout<<stol(s1)+stol(s2);
	return 0;
}
