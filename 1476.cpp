#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int E,M,S;
    cin >> E>>S>>M;
    int a,b,c;
    int cnt =0;
    while(true){
    	a=cnt%15 +1;
    	b=cnt%28 +1;
    	c=cnt%19 +1;
    	if(a==E && b==S && c==M){
    		cout<<cnt+1;
    		break;
		}
		cnt++;
	}
}

