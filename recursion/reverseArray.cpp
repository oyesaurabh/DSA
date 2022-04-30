#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void insertAtLast(vector<int> &a,int e){
    if(a.empty()){
        a.push_back(e);return;
    }
    int t=a.back();
    a.pop_back();
    insertAtLast(a,e);
    a.push_back(t);
}
void rev(vector<int> &a){
    if(a.empty())return;
    int t=a.back();
    a.pop_back();
    rev(a);
    insertAtLast(a,t);
}
int main(){
    //here
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;

    rev(a);
    for(int i:a)
        cout<<i<<" ";    
    getch();
    return 0;
}