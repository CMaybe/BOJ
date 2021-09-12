#include <string>
#include<iostream>
#include <cstring>
using namespace std;

int main()
{
	int arr[4];
    string s;
	while(getline(cin, s)){
        memset(arr, 0, sizeof(arr));
		for(int i = 0;i<s.length();i++){
			if(s[i]>='a' && s[i]<='z') arr[0]++;
			if(s[i]>='A' && s[i]<='Z') arr[1]++;
			if(s[i]>='0' && s[i]<='9') arr[2]++;
			if(s[i]==' ') arr[3]++;
		}
		cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<' '<<arr[3]<<'\n';
	}
	
	return 0;
	
}
