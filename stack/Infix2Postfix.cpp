#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;
int pre(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else 
        return 0;
}
int isOperator(char c){
    if(c=='*' || c=='-' || c=='/' || c=='+' || c=='^')
        return 1;
    else    
        return 0;
}
string Infix2Postfix(string str){
    stack<char> s;
    string postfix="";
    for(int i=0;i<str.length();i++){
        if( str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z' )
            postfix+=str[i];
        else if(str[i]=='(')
            s.push(str[i]);
        else if(str[i]==')'){
            while(s.top()!='('){
                postfix+=s.top();
                s.pop();
            }s.pop();}
        else{
            while(!s.empty()&&pre(s.top())>=pre(str[i])){
                postfix+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    
    return postfix;
}
int main(){
    cout<<"Expression: \n";
    string str;
    cin>>str;
    cout<<"infix: "<<str<<"\n";
    cout<<"postfix: "<<Infix2Postfix(str)<<"\n";
    getch();
    return 0;
}
