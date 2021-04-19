#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[501];
int n;

typedef struct LINE{
    int a;
    int b;
}Line;

bool compare(Line A,Line B){
    return A.a<B.a;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin>>n;
	vector<Line> v;
	int _min=0,cnt=0;
	for(int i = 0;i<n;i++){
	    Line temp;
	    cin>>temp.a>>temp.b;
	    v.push_back(temp);
	}
	int _max=-1;
	sort(v.begin(),v.end(),compare);
	for(int i = 1;i<=n;i++){
	    arr[i]=1;
	    for(int j = i;j>=1;j--){
	        if(v[i-1].b>v[j-1].b && (arr[j]+1>arr[i])){
	            arr[i]=arr[j]+1;
	            _max = max(_max,arr[i]);
	        }
	    }
	}
	
	cout<<n-_max;

	return 0;
}
