#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[1002][1002];
string s[1002][1002];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 0;i<1002;i++){
		for(int j = 0;j<1002;j++){
			s[i][j]= "";
		}
	}
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]){
				arr[i][j] = arr[i - 1][j - 1] + 1;
				s[i][j] = s[i-1][j-1] + s1[i-1];
			}
			else {
				if(arr[i - 1][j] > arr[i][j - 1]){
					arr[i][j] = arr[i - 1][j];
					s[i][j] = s[i-1][j];
				}
				else{
					arr[i][j] = arr[i][j-1];
					s[i][j] = s[i][j-1];
				}
			}
		}
	}

	cout << arr[s1.length()][s2.length()]<<'\n';
	if(arr[s1.length()][s2.length()]>0)cout<<s[s1.length()][s2.length()];
	return 0;
}
