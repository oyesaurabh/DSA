//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void merge(int a[],int l,int m ,int h){
    int i=l,j=m+1,k=0;
    int b[h-l+1]; 
    while(i<=m && j<=h){
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=h)
        b[k++]=a[j++];
    
    for(int i=0;i<h-l+1;i++)
        a[i+l]=b[i];
}
void recursiveMergeSort(int a[],int l,int h){
    if(l<h){
        int m=(l+h)/2;
        recursiveMergeSort(a,l,m);
        recursiveMergeSort(a,m+1,h);
        merge(a,l,m,h);
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
    recursiveMergeSort(a,0,n-1);
    for(int x:a)
        cout<<x<<" ";

    getch();
    return 0;
}