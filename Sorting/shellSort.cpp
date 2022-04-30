//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void shellSort(int a[],int n){

    int gap = n/2; 
    while(gap)  
    {  
        for (int i = gap; i < n; i ++)  
         
            for (int j = i-gap; j >=0 ; j -= gap)
                if(a[j]>a[j+gap])  
                    swap(a[j], a[j + gap]);  
                else 
                    break;
        
        gap /= 2;  
    }  
}
int main(){
    //here
    cout<<"N: ";
    int n;
    cin>>n;
    cout<<"enter "<<n<<" elements\n";
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    shellSort(a,n);
    for(int x:a)
        cout<<x<<" ";

    getch();
    return 0;
}