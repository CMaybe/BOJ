#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;

	
typedef struct NODE{
	int x;
	int y;
}Node;

bool visit[1501][1501];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	queue<Node> q;
	int a, b, c,sum;
	cin>> a>>b>>c;
	sum = a + b + c;
	if(sum % 3 != 0){
		cout<<0;
		return 0;
	}
	q.push({a,b});
	while(q.empty()==false){
		Node p = q.front();
		
		visit[p.x][p.y] = true;
		visit[p.y][p.x] = true;
		q.pop();
		if(sum/3==p.x && p.x==p.y){
			cout<<1;
			return 0;
		}
		int arr[] = {p.x,p.y,sum- p.x - p.y};
		for(int i  = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(arr[i]<arr[j]){
					int arr2[] = {p.x,p.y,sum- p.x - p.y};
					arr2[i] +=arr[i];
					arr2[j] -=arr[i];
					if(visit[arr2[0]][arr2[1]]) continue;
					q.push({arr2[0], arr2[1]});
				}
			}
		}
	}
	cout<<0;
	
	return 0;
	
}
