//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void help(string ip,string op){
    if(ip.empty()){
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(toupper(ip[0]));
    op2.push_back(ip[0]);
    
    ip.erase(ip.begin()+0);
    help(ip,op1);
    help(ip,op2);
}
int main(){
    //here
    string ip;
    cout<<"IP : ";
    cin>>ip;
    string op;
    help(ip,op);
    getch();
    return 0;
}