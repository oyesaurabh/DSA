//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int j,k;
        j=k=i;
        while(j<n){
            if(a[j]<a[k])
                k=j;
            j++;
        }
        swap(a[k],a[i]);
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
    selectionSort(a,n);
    for(int x:a)
        cout<<x<<" ";

    getch();
    return 0;
}