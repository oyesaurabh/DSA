#include <iostream>
using namespace std;

int main() 
{
    int m;
    cin>>m;
    if(m%2==0){
      cout<<"ODD no. please";
      return 0;
    }
    int space=m/2;
    int star=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=space;j++)
            cout<<"  ";
        
        for(int j=1;j<=star;j++)
            cout<<"* ";
            // j==1||j==star?cout<<"* ":cout<<"  ";
        
        cout<<"\n";

        if(i <= (m/2)){
            //upper half
            space--;
            star += 2;
        }
        else{
            //lower half
            space++;
            star -= 2;
        }
    }

    return 0;
}