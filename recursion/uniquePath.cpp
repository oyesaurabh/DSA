//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int m,n;
    //recursion TLE
    // int find(int i,int j,int m,int n){
    //     if(i==m-1 || j==n-1)return 1;
    //     return find(i+1,j,m,n)+find(i,j+1,m,n);
    // }
    
    //memo
    int find(int i,int j,vector<vector<int>>& a){
        if(i==m-1 || j==n-1)return 1;
        if(a[i][j]>0)return a[i][j];
        a[i][j]=find(i+1,j,a)+find(i,j+1,a);
        return a[i][j];
    }

int main(){
    //here
    cout<<"m: ";
    cin>>m;
    cout<<"N: ";
    cin>>n;
    vector<vector<int>> dp(m,vector<int>(n,0));
    cout<<"total number of ways = "<<find(0,0,dp);
    getch();
    return 0;
}