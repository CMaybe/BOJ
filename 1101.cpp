#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
	    unsigned int x,y,cnt;
	    cin>>x>>y;
	    y-=x;
	    x=1;
        cnt=1;
        for(int i = 2;x<y;i++){
	        x+=i/2;
	        cnt++;
	    }
	    if(x>y) cnt--;
	    cout<<cnt<<'\n';
	    
	}
	
}
