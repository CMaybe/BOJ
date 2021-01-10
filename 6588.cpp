#include <iostream>
#include <vector>
using namespace std;
int primes[1000001];

int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
	vector<int> vec;
	primes[0]=primes[1]=1;
	for(int i =2;i<=1000;i++){
		int j =2;
		while (i*j<=1000000){
			primes[i*j]=1;
			j++;
		}
	}
	for(int i = 2;i<=1000000;i++){
		if(primes[i]==0){
			vec.push_back(i);
		} 
	}
    int num;
    
    while(true){
		cin >> num;
		bool flag = true;
		if(num==0) break;
    	for(int i =0;i<vec.size() && vec[i]<num;i++){
    	    if(primes[num-vec[i]]==0){
                cout<<num<<" = "<< vec[i]<<" + "<<num-vec[i]<<"\n";
    		    break;
    	    }
		}
	}
}


