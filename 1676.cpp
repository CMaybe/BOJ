#include <iostream>

using namespace std;

int main()
{
    int n,n2=0,n5=0;
    cin >>n;

    for(int i =2;i<=n;i++){
        int j  = i;
        while(j%2==0){
            j/=2;
            n2++;
        }
        j  = i;
        while(j%5==0){
            j/=5;
            n5++;
        }
    }
    
    cout<< (n2>n5? n5:n2);
    return 0;
}
