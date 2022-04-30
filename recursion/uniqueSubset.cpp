#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
set<string> Set;
void uniqueSub(string ip,string op){
    if(ip.empty()){
        Set.insert(op);
        return;
    }
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    uniqueSub(ip,op);
    uniqueSub(ip,op2);
}
int main(){
    string s;
    cin>>s;
    uniqueSub(s,"");
    for(auto i:Set)cout<<i<<" ";
    getch();
    return 0;
}