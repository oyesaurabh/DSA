//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void per(string ip,string op){
    if(ip.empty()){
        cout<<op<<"\n";
        return;
    }
    string op1=op+ip[0];
    string op2=op+"_"+ip[0];
    ip.erase(ip.begin()+0);
    per(ip,op1);
    per(ip,op2);
}
int main(){
    string ip;
    cout<<"S=: ";cin>>ip;
    string op="";
    op+=ip[0];
    ip.erase(ip.begin()+0);
    per(ip,op);
    getch();
    return 0;
}