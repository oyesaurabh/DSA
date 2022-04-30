//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void TOH(int n,char a='a',char b='b',char c='c'){
    if(n){
        TOH(n-1,a,c,b);
        cout<<a<<" => "<<c<<"\n";
        TOH(n-1,b,a,c);
    }
}
int main(){
    //here
    int n;
    cout<<"N: ";
    cin>>n;
    TOH(n);
    getch();
    return 0;
}