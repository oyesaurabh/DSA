//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void insertAtBottom(stack<int> &s,int e){
    if(s.empty()){
        s.push(e);
        return;
    }
    int t=s.top();
    s.pop();
    insertAtBottom(s,e);
    s.push(t);
}
void rev(stack<int> &s){
    if(s.empty())return;
    int t=s.top();
    s.pop();
    rev(s);
    insertAtBottom(s,t);
}
int main(){
    //here
     stack<int> s;
    int n;
    cout<<"N: ";
    cin>>n;
    while(n--){
        int e;
        cin>>e;
        s.push(e);
    }
    rev(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    getch();
    return 0;
}