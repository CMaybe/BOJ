#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


typedef struct NODE{
	int node;
	int level;
	int left;
	int right;
}Node;

vector<int> v;
Node tree[10001];
int level[10001][2];
int _max = -1;
int sub=0;

void make(int node){
	if(tree[node].left != -1){
		tree[tree[node].left].level = tree[node].level +1;
		auto it = find(v.begin(),v.end(),node);
		v.insert(it,tree[node].left);
		make(tree[node].left);
	}
	if(tree[node].right != -1){
		tree[tree[node].right].level = tree[node].level +1;
		auto it = find(v.begin(),v.end(),node);
		if(it+1  >= v.end()) v.push_back(tree[node].right);
		else v.insert(it+1,tree[node].right);
		make(tree[node].right);
	}
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
	int n,m,r,l;
	int arr[100000];
	cin>>n;
	for(int i = 0;i<n;i++){
		level[i+1][0]=1000000;
		level[i+1][1]=-1;
		cin>>m>>l>>r;
		tree[m].left = l;
		tree[m].right = r;
		if(r!=-1)arr[r]=m;
		if(l!=-1)arr[l]=m;
	}
	int t=n;
	while(arr[t]!=0){
		t=arr[t];
	}
	tree[t].level=1;	
	v.push_back(t);
	make(t);
	int _max = -1,idx;
	for(int i = 1;i<=n;i++){
		level[tree[i].level][0] = min(level[tree[i].level][0], static_cast<int>(find(v.begin(),v.end(),i) - v.begin()));
		level[tree[i].level][1] = max(level[tree[i].level][1], static_cast<int>(find(v.begin(),v.end(),i) - v.begin()));
		int d = level[tree[i].level][1] - level[tree[i].level][0];
		if(d >= _max){
			if(d==_max){
				_max = level[tree[i].level][1] - level[tree[i].level][0];
				idx = min(tree[i].level,idx);
			}
			else{
				_max = level[tree[i].level][1] - level[tree[i].level][0];
				idx = tree[i].level;
			}
		}
	}
	cout<<idx<<' '<<_max + 1;
    return 0;
}
