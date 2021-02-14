#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int arr[52][52];

typedef struct POINT{
    int x;
    int y;
}Point;



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n,m,t;
    cin>>n>>m;
    vector<Point> house;
    vector<Point> ch;
    vector<int>mask;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin>>t;
            if(t==1) house.push_back({j,i});
            if(t==2) ch.push_back({j,i});
        }
    }
    
    for(int i =0;i<ch.size()-m;i++){
        mask.push_back(0);
    }
    for(int i = 0;i<m;i++){
        mask.push_back(1);
    }
    int _min = 1e9;
    do{
        int sum = 0;
        for(int i = 0;i<house.size();i++){
            int temp =1e9;
            for(int j=0;j<ch.size();j++){
                if(mask[j]==0)continue;
                int a=abs(ch[j].x-house[i].x) + abs(ch[j].y-house[i].y);
                if(a<temp)temp=a;
            }
            sum+=temp;
        }
        if(sum<_min)_min=sum;
    }while(next_permutation(mask.begin(),mask.end()));
    
    
    cout<<_min;
    return 0;
}
