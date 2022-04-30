//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
double power(double x,int n){
    double ans=1.0;
    bool sign=(n<0)?1:0;
    if(x==1 || n==0)return 1.0;
    else{
        if(n<0)n=abs(n);
        if(n&1)                           // 2^5 = 2*(2^4) , 2^6 = (2*2)^3
            ans=x*power(x,n-1);
        else
            ans=ans*power(x*x,n/2);
    }
    if(sign)
        ans=1.0/ans;
    return ans;
}
int main(){
    //here
    double x,y;
    cout<<"X ^ n\n";
    bool exit=1;
    while(exit){
        cin>>x>>y;
        cout<<"ANS = "<<power(x,y)<<"\n";
        cout<<"wanna exit ?(0 for exit) ";cin>>exit;
    }
    return 0;
}