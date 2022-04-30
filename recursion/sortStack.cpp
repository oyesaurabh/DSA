//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void insert(stack<int> &s,int e){
    if(s.empty() || s.top()<e){
        s.push(e);
        return;
    }
    int t=s.top();
    s.pop();
    insert(s,e);
    s.push(t);
}
void sort(stack<int> &s){
    if(s.empty())return;
    int t=s.top();
    s.pop();
    sort(s);
    insert(s,t);
}
int main(){
    //here
    stack<int> s;
    int n;
    cout<<"N : ";
    cin>>n;
    while(n--){
        int t;cin>>t;
        s.push(t);
    }
    sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<"\n";
    getch();
    return 0;
}