#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<string> s = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	string in;
	cin >> in;
	for (int i = 0; i < s.size(); i++) {
		try
		{
			in.replace(in.find(s[i]), s[i].length(), "_");
			i -= 1;
		}
		catch (const std::exception&)
		{
		}
	}
	cout << in.length();

}	
