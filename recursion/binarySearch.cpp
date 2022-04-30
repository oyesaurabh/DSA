//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int binarySearch(int a[],int l,int h,int k){
    if(l>h)
        return -1;

    int m=(l+h)/2; 
    if(a[m]>k)
        return binarySearch(a,l,m-1,k);
    else if(a[m]<k)
        return binarySearch(a,m+1,h,k);
    else 
        return m;
}

int main(){
    //here
    int n;
    cout<<"N: ";
    cin>>n;
    int a[n];
    cout<<"enter "<<n<<" sorted elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"\nwhat to search: ";
    int k;
    cin>>k;
    cout<<"\nAT: "<<binarySearch(a,0,6,k);
    getch();
    return 0;
}