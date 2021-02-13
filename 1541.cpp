#include <iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    string s;
    vector<string> v;
    cin>>s;
    char * temp = new char[s.size() + 1];
    std::copy(s.begin(), s.end(), temp);
    temp[s.size()] = '\0';
    temp = strtok(temp,"-");
    do{
        v.push_back(string(temp));
        temp = strtok(NULL,"-");
    }while(temp!=NULL);
    delete[] temp;
    
    
    int ans =0;
    bool isfirt=true;
    for(string t : v){
        temp = new char[t.size() + 1];
        std::copy(t.begin(), t.end(), temp);
        temp[t.size()] = '\0';
        temp = strtok(temp,"+");
        int sum =0;
        do{
           sum+=stoi(string(temp));
           temp = strtok(NULL,"+"); 
        }while(temp!=NULL);
        if(isfirt){
            ans+=sum;
            isfirt=false;
        }
        else ans-=sum;
        delete[] temp;
    }
    cout<<ans;
    
    return 0;
}
