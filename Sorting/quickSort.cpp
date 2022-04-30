//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int partition(int A[], int l, int h){
    int pivot=A[l];
    int i=l,j=h;
    
    while(i<j)
    {
        while(A[i]<=pivot)
            i++;
        while(A[j]>pivot)
            j--;
 
        if(i<j)
            swap(A[i],A[j]);
    }
 
 swap(A[l],A[j]);
 return j;
}
void quickSort(int a[],int s,int e){
    if(s<e){
        int m=partition(a,s,e);
        quickSort(a,s,m-1);
        quickSort(a,m+1,e);
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
    quickSort(a,0,n-1);
    for(int x:a)
        cout<<x<<" ";

    getch();
    return 0;
}