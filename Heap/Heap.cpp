//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class heap{
    vector<int> a;
    public:
    void insert(int e);
    int del();
    void display();
    void heapsort(vector<int> &v){    
        for(int i=0;i<v.size();i++)
            insert(v[i]);
    }
};
void heap::insert(int e){
    
    a.push_back(e);
    int n=a.size();
    int i=n-1;
    while(i>0 && a[i/2] < a[i]){
        swap(a[i/2],a[i]);
        i/=2;
    }
}
int heap::del(){
    if(a.empty()) -1;
    int e=a[0];
    int n=a.size()-1;
    a[0]=a[n];
    a.erase(a.begin()+n);
    int i=1,j=2,k=0;
    while (j<=n)
    {
        if(a[i] > a[j]){
            swap(a[i],a[k]);
            k=i;
        }
        else{
            swap(a[j],a[k]);
            k=j;
        }
        i=k*2;
        j=k*2+1;
    }
    
    return e;
}
void heap::display(){
    cout<<"\n";
    for(auto it:a)cout<<it<<" ";
    cout<<"\n";
}
int main(){
    //here
    heap h;
    do{
        cout<<"1.insert 2.delete 3.display 4.heapSort 5.exit\n";
        int n;
        cin>>n;
        if(n==1){
            int e;cin>>e;
            h.insert(e);
        }
        else if(n==2){
                cout<<"deleted element\t"<<h.del()<<"\n";
        }
        else if(n==3){
            h.display();
        }
        else if(n==4){
            int size;
            cout<<"\nenter size\n";
            cin>>size;
            vector<int> v(size,0);
            cout<<"enter array elements\n";
            for(auto &x:v)cin>>x;
            h.heapsort(v);
        }
        else 
            break;
    }while(1);
    
    return 0;
}