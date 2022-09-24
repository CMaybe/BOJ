#include <iostream>
#include <algorithm>


using namespace std;
typedef struct BALL{
    int idx;
    int color;
    long long _size;
    long long ans;
    
}Ball;


bool comp(const Ball& a,const Ball& b){
    if (a._size==b._size) return a.color < b.color;
    return a._size < b._size;
}

bool comp2(const Ball& a,const Ball& b){
    return a.idx < b.idx;
}


Ball ball[200002];
long long color[200002];
long long _size[200002];
long long sum;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        ball[i].idx = i;
        cin>>ball[i].color >> ball[i]._size;
    }
    sort(ball+1,ball+n+1,comp);
    for(int i = 1;i<=n;i++){
        color[ball[i].color] += ball[i]._size;
        _size[ball[i]._size] += ball[i]._size; 
        sum += ball[i]._size;
        ball[i].ans = sum - color[ball[i].color] - _size[ball[i]._size] + ball[i]._size;
        if(ball[i]._size == ball[i-1]._size && ball[i].color == ball[i-1].color){
            ball[i].ans = ball[i-1].ans;
        }
        
    }
    sort(ball+1,ball+n+1,comp2);
    for(int i=1;i<=n;i++){
        cout << ball[i].ans << '\n';
    }
    
}
