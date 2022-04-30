//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void Merge(int A[],int l,int mid,int h) 
{ 
    int i=l,j=mid+1,k=l; 
    int B[h+1]; 
    while(i<=mid && j<=h) 
    { 
        if(A[i]<A[j]) 
        B[k++]=A[i++]; 
        else
        B[k++]=A[j++]; 
    } 
    for(;i<=mid;i++) 
        B[k++]=A[i]; 
    for(;j<=h;j++) 
        B[k++]=A[j]; 
    for(i=l;i<=h;i++) 
        A[i]=B[i]; 
}
void mergeSortI(int A[], int n){
    int p;
    for (p=2; p<=n; p=p*2){
        for (int i=0; i+p-1<n; i=i+p){
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
    }
    if (p/2 < n){
        Merge(A, 0, p/2-1, n-1);
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
    mergeSortI(a,n);
    for(int x:a)
        cout<<x<<" ";
    getch();
    return 0;
}