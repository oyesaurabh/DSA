#include<iostream>
#include<conio.h>
using namespace std;
int main(int argc, char const *argv[])
{   void TOH(int,char,char,char);
    int n;
    cout<<"enter number of disk: ";
    cin>>n;
    TOH(n,'A','B','C');
    getch();
    return 0;
}
void TOH(int n,char a, char b, char c)
{
if(n==0)
return;

TOH(n-1,a,c,b);
    cout<<a<<" to "<<c<<"\n";
TOH(n-1,b,a,c);

}
