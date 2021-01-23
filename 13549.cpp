#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
int arr[100001];
deque<int> dq;
int n,k;
void bfs(){
    while(!dq.empty()){
        int c =dq.back();
        dq.pop_back();
        if(c==k){
            cout<<arr[k];
            return;
        }

        if(c*2 <=100000 && arr[c*2]==-1){
                arr[c*2]=arr[c];
                dq.push_back(c*2);
        }
        if(c>0&&arr[c-1]==-1){
            arr[c-1]=arr[c]+1;
            dq.push_front(c-1);
        }
        if(c<100000 && arr[c+1]==-1){
            arr[c+1]=arr[c]+1;
            dq.push_front(c+1);
        }
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    memset(arr,-1,sizeof(arr));
    
    cin >>n>>k;
    arr[n]=0;
    dq.push_back(n);
    bfs();
    
    return 0;
}
