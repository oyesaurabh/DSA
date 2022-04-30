#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void help(int open,int close,string s){
    if(open==0 && close==0){
        cout<<s<<" ";
        return;
    }
    if(close<open || open<0 || close<0)return;    
    help(open-1,close,s+'(');
    help(open,close-1,s+')');
}
int main(){
    int n;
    cout<<"N :";
    cin>>n;
    help(n,n,"");
    
    getch();
    return 0;
}