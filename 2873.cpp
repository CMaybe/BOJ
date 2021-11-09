#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int arr[1001][1001];

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int r, c, sum = 0, min = 1e9;
	int mr=0, mc=0;
	cin >> r >> c;
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			cin>>arr[i][j];
			if(arr[i][j]<min && (i+j)%2==1){
				min = arr[i][j];
				mc=j;
				mr=i;
			}
		}
	}
	
	if(r%2==1){
		for(int i = 1;i<=r;i++){
			for(int j = 1;j<c;j++) cout << (i%2==1 ? 'R' : 'L');
			if(i<r) cout<<'D';
		}
	}
	else if(c%2==1){
		for(int j = 1;j<=c;j++){
			for(int i = 1;i<r;i++) cout << (j%2==1 ? 'D' : 'U');
			if(j<c) cout<<'R';
		}
	}
	else{
		if(mc%2==1){
			for(int i = 1;i<mr-1;i++){
				for(int j = 1;j<c;j++) cout << (i%2==1 ? 'R' : 'L');
				cout<<'D';
			}
			bool flag = true;
			for(int j = 1;j<mc;j++){
				cout << (flag ? 'D' : 'U');
				flag ^= true;
				cout << 'R';
			}
			flag = false;
			cout << "RD";
			for(int j = mc+1;j<c;j++){
				cout <<'R';
				cout << (flag ? 'D' : 'U');
				flag ^= true;
			}
			if(mr<r) cout <<'D';
			for(int i = mr+1;i<=r;i++){
				for(int j = 1;j<c;j++) cout << (i%2==0 ? 'R' : 'L');
				if(i<r) cout<<'D';
			}
		}
		else if(mr%2==1){
			for(int i = 1;i<=mr-1;i++){
				for(int j = 1;j<c;j++) cout << (i%2==1 ? 'R' : 'L');
				cout<<'D';
			}
			bool flag = true;
			for(int j = 1;j<mc-1;j++){
				cout << (flag ? 'D' : 'U');
				flag ^= true;
				cout << 'R';
			}
			flag = false;
			cout << "DR";
			for(int j = mc+1;j<=c;j++){
				cout <<'R';
				cout << (flag ? 'D' : 'U');
				flag ^= true;
			}
			if(mr+1<r) cout <<'D';
			for(int i = mr+2;i<=r;i++){
				for(int j = 1;j<c;j++) cout << (i%2==0 ? 'R' : 'L');
				if(i<r) cout<<'D';
			}
		}
	}
	
	return 0;
	
}
