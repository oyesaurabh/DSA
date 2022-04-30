//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void reverse(string s){
    stack<char> sta;
    int n=s.size();
    for(int i=0;i<n;i++)
        if(s[i] != ' ')
            sta.push(s[i]);
        else{
            while(!sta.empty()){
                cout<<sta.top();
                sta.pop();
            }
        cout<<" ";
        }
    while(!sta.empty()){
        cout<<sta.top();
        sta.pop();
    }
    
}
int main(){
    //here
    string s;
    cout<<"string \n";
    cin>>s;
    reverse(s);
    getch();
    return 0;
}