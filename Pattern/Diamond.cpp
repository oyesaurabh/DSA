#include <iostream>
using namespace std;

int main() 
{
    int m;
    cin>>m;
    if(m%2==0){
      cout<<"ERROR: odd number dedo bro...";
      return 0;
    }
    
    for(int j=1;j<=m;j++)cout<<"* ";cout<<"\n";
    
    int s=1, star=m/2;
    for(int i=1;i<=m-2;i++){
      for(int j=1;j<=star;j++)cout<<"* ";
      for(int j=1;j<=s;j++)cout<<"  ";
      for(int j=1;j<=star;j++)cout<<"* ";
      cout<<"\n";
      
      if(i<m/2)
        s+=2,star--;
      else 
        s-=2, star++;
    }
    
    for(int j=1;j<=m;j++)cout<<"* ";cout<<"\n";
}