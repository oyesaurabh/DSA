#include<iostream>
#include<stack>
#include<math.h>
#include<conio.h>
using namespace std;
int evaluate(string &str){
    stack<int> s;
    for(int i=0;i<str.length();i++){
        if(str[i]-'0'>=0 && str[i]-'0'<=9)
            s.push(str[i] - '0');
        else{
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            switch (str[i])
            {
                case '*':
                    s.push(x*y);
                    break;
                case '+':
                    s.push(x+y);
                    break;
                case '-':
                    s.push(y-x);
                    break;
                case '/':
                    s.push(y/x);
                    break;
                case '^':
                    s.push(pow(y,x));
                    break;
                default:
                    break;
            }
        }
    }
    return  s.top();
}
int main(){
    string s;
    cout<<"exp in PostFix: ";
    cin>>s;
    cout<<"ANS: "<<evaluate(s)<<"\n";
    getch();
    return 0;
}