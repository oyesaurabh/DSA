//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void onetoN(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    onetoN(n-1);
    cout<<n<<" "; 
}
void Nto1(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    Nto1(n-1);
}
int main(){
    int n;
    cin>>n;
    Nto1(n);
    cout<<"\n";
    onetoN(n);
    getch();
    return 0;
}