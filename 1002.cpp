#include<iostream>
#include<cmath>
#include <iomanip> 

using namespace std;
#define PI 3.141593
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cout<<setprecision(5);
	cout<<fixed;
	
	double x1,x2,y1,y2,r1,r2;
	int t;
	cin>>t;
	while(t--){
	    cin>>x1>>y1>>r1>>x2>>y2>>r2;
	    double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	    if(x1==x2 && y1==y2 && r1==r2){
	        cout<<"-1\n";
	    }
	    else if(r1+r2==d || abs(r1-r2)==d){
	        cout<<"1\n";
	    }
	    else if(d<r1+r2 && d>abs(r2-r1)){
	        cout<<"2\n";
	    } 
	    else cout<<"0\n";
	
	}
	
	
	
}
