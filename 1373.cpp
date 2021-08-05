#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
	string s;
	cin>>s;
	while(s.length()%3!=0){
		s = "0" + s;
	}
	for(int i = 0;i<s.length();i+=3){
		int t = (s[i] - '0')*4 + (s[i+1] - '0')*2 +(s[i+2] - '0');
		cout<<t;
	}
    return 0;
}

