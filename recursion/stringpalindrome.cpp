//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
bool palindrome(string s,int i,int j){
    if(i>=j)return 1;
    if(s[i] != s[j])return 0;
    return palindrome(s,i+1,j-1);
}
int main(){
    //here
    string s;
    cin>>s;
    if(palindrome(s,0,s.size()-1))cout<<"YES";
    else cout<<"NO";
    getch();
    return 0;
}