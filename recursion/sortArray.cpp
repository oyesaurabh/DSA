//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void insert(vector<int> &a,int e){
    if(a.empty() || a.back()<e){
        a.push_back(e);
        return;
    }
    int t=a.back();
    a.pop_back();
    insert(a,e);
    a.push_back(t);
}
void sortArray(vector<int> &a){
    if(a.empty())return;
    int t=a.back();
    a.pop_back();
    sortArray(a);
    insert(a,t);
}
int main(){
    //here
    cout<<"N: ";
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    sortArray(a);
    for(auto i:a)cout<<i<<" ";
    getch();
    return 0;
}