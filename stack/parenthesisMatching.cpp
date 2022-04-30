#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;
bool parenthesisMatching(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){

        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            s.push(str[i]);

        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(s.empty())
                return false;
            switch (s.top())
            {
            case '(':
                if(str[i]==')')
                    s.pop();
                else 
                    return false;
                break;
            case '{':
                if(str[i]=='}')
                    s.pop();
                else
                    return false;
                break;
            case '[':
                if(str[i]==']')
                    s.pop();
                else
                    return false;
                break;
            default:
                break;
            }
        }
    }
    return s.empty();
}
int main(){
    string s;
    cin>>s;
    if(parenthesisMatching(s))
        cout<<"YES";
    else
        cout<<"NO";
    getch();
    return 0;
}