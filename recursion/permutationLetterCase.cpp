#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void help(string ip,string op){
    if(ip.empty()){
        cout<<op<<" ";
        return;
    }
    char c=ip[0];
    ip.erase(ip.begin()+0);
    if(  isdigit(c) ){
        help(ip,op+c);
        return;
    }

    string op1=op;
    op1.push_back( tolower(c) );
    string op2=op;
    op2.push_back( toupper(c) );

    help(ip,op1);
    help(ip,op2);

}
int main(){
    string ip;
    cout<<"IP: ";
    cin>>ip;
    help(ip,"");
    getch();
    return 0;
}