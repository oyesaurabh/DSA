//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void countSort(int a[],int n){
    int m=*max_element(a,a+n);
    int *c;
    c=new int[m+1];
    for(int i=0;i<=m;i++)
        c[i]=0;
    for(int i=0;i<n;i++)
        c[a[i]]++;
    
    int k=0;
    for(int i=0;i<=m;i++)
        while (c[i] != 0){
            a[k++]=i;
            c[i]--;
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
    countSort(a,n);
    for(int x:a)
        cout<<x<<" ";

    getch();
    return 0;
}