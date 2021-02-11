#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        x-=1;
        y-=1;
        bool flag = false;
        for(int j=x;j<(m*n);j+=m){
            if(j%n==y){
                cout << j+1<<'\n';
                flag = true;
                break;
            }
        }
        if(flag==false) cout<<"-1\n";
    }

    return 0;
}
