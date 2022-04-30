//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void middle(stack<int> &s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int t=s.top();
    s.pop();
    middle(s,k-1);
    s.push(t);
}
int main(){
    //here
    stack<int> s;
    int n;
    cout<<"N: ";
    cin>>n;
    int k=(n/2)+1;
    while(n--){
        int e;
        cin>>e;
        s.push(e);
    }
    middle(s,k);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    getch();
    return 0;
}