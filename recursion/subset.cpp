//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
vector<string> a; 
void subset(string ip,string op,int i,int n){
    if(i>=n){
        a.push_back(op);
        return;
    }
    char first=ip[i];
    subset(ip,op+first,i+1,n); //taking 
    subset(ip,op,i+1,n);  //ignoring
}
int main(){
    //here
    string ip;
    cin>>ip;
    subset(ip,"",0,ip.size());
    for(auto i:a)cout<<i<<"\n";
    getch();
    return 0;
}