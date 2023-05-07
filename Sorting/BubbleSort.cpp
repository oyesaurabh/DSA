//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void BubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1])
                swap(a[j],a[j+1]);
}
int main(){
    //here 
    int n;
    cout<<"N: ";
    cin>>n;
    int a[n];
    cout<<"enter "<<n<<" elements \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    BubbleSort(a,n);
    for(int x:a)
        cout<<x<<" ";
    getch();
    return 0;
}