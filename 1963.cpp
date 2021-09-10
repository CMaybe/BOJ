#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

bool isPrime[10000];

typedef struct NODE{
	int n;
	int t;
}Node;

void prime()
{
    for (int i = 2; i <= 9999; i++) isPrime[i] = true;
    for (int i = 2; i <= sqrt(9999); i++)
    {
        if (isPrime[i] == false) continue;
        for (int j = i * i; j <= 9999; j += i) isPrime[j] = false;
    }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin>> n;
	prime();
	while(n--){
		int a,b;
		cin>>a>>b;
		queue<Node> q;
		q.push({a,0});
		bool visit[10000] = {false,};
		while(!q.empty()){
			Node cur = q.front();
			q.pop();
			visit[cur.n] = true;
			if(cur.n==b){
				cout<<cur.t<<'\n';
				break;
			}
			for(int j = 0;j<4;j++){
				for(int i = 0;i<=9;i++){
					if(i==0 && j==0) continue;
					string s = to_string(cur.n);
					if(s[j] ==  static_cast<char>('0'+i)) continue;
					s[j] = static_cast<char>('0'+i);
					if(visit[stoi(s)]) continue;
					if(isPrime[stoi(s)]) q.push({stoi(s),cur.t+1});
				}
			}	
		}
	}
	
	
	return 0;
	
}
