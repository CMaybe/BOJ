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
	string s;
	cin>>s;
	int sum=0;
	bool flag = false;
	sort(s.begin(), s.end(), greater<char>());
	for(int i = 0;i<s.length();i++){
		if(s[i]=='0') flag = true;
		sum += static_cast<int>(s[i]-'0');
	}
	if(sum%3==0 && flag == true) cout<< s;
	else cout << "-1";
	return 0;
	
}
