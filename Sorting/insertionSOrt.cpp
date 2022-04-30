//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int t=a[i];
        int j=i-1;
        while(a[j]>t && j>=0)
            a[j+1]=a[j--];
        a[++j]=t;
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
    insertionSort(a,n);
    for(int x:a)
        cout<<x<<" ";

    getch();
    return 0;
}