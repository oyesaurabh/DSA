#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void permutation(char *c,int l,int h){
    if(l==h)
        cout<<c<<endl;
    else
        for(int i=l; i<=h; i++)
        {
            swap(c[l],c[i]);
            permutation(c,l+1,h);
            swap(c[l],c[i]);
        }
    
}
int main(){
    char c[50];
    gets(c);
    int l=strlen(c);
    cout<<"\n";
    permutation(c,0,l-1);
    getch();
    return 0;
}