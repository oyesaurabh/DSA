#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    if(m%2==0){
        cout<<"Odd number dedo vro...";
        return 0;
    }
    
    int space=m/2;
    int star=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=space;j++)
            cout<<"  ";
        
        /*
        To print hollow Diamond...
         for(int j=1;j<=star;j++){
            if (j == 1 || j == star) {
                cout<<"* ";
            }
            else {
                cout<<"  ";
            }
        }        
        */
        for(int j=1;j<=star;j++)
            cout<<"* ";
        
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
