//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
#define I INT_MAX 
using namespace std;
class graph{
    private:
    int v;
    vector<vector<int>> *cost;
    vector<int> *near;
    vector<pair<int,int>> ans;
    public:
        graph(int v){
            this->v=v;
            near=new vector<int>(v+1,I);
            cost=new vector<vector<int>>(v+1,vector<int>(v+1,I));
        }
    void add(int v1,int v2,int c){
        (*cost)[v1][v2]=c;
        (*cost)[v2][v1]=c;
    }
    ~graph(){
        delete cost;
        delete near;
    }

    void print();
    void prims();
    void kruskals();

};
void graph::print(){
    cout<<"\nANS:\n";

    for(auto it:ans)
        cout<<"( "<<it.first<<", "<<it.second<<" )"<<"\n";
        
}
void graph::prims(){
    // actual code starts from here

    //finding min cost from graph
    int minimum=I,u,v;
    for(int i=1;i<=v;i++)
        for(int j=i;j<=v;j++)
            if( (*cost)[i][j]<minimum){
                minimum=(*cost)[i][j];
                u=i;v=j;
            }
    

    ans.push_back({u,v});
    (*near)[u]=(*near)[v]=0;

    // initial steps
    for(int i=1;i<=v;i++)
        if( (*near)[i] != 0){
            if((*cost)[i][u] < (*cost)[i][v])
                (*near)[i]=u;
            else
                (*near)[i]=v;
        }

    //final steps
    for(int i=1;i<=v-1;i++){

        //finding min edge
        int min=I,k;
        for(int j=1;j<=v;j++)
            if( (*near)[j]!=0 && (*cost)[j][(*near)[j]]<min ){
                min=(*cost)[j][(*near)[j]];
                k=j;
            }

        (*near)[k]=0;
        ans.push_back({k,(*near)[k]});

        //updation
        for(int j=1;j<=v;j++)
            if((*near)[j] !=0 && (*cost)[j][k] < (*cost)[j][(*near)[j]])
                (*near)[j]=k;

        }

}
int main(){
    //here
    system("CLS");
    label:
    cout<<"enter number of vectices in Graph\n";
    int v;
    cin>>v;
    graph g(v);
    int e;
    cout<<"edges?\t";
    cin>>e;
    system("CLS");
    cout<<"\nenter "<<e<<" edges alongs with its cost\n";
    while(e--){
        int e1,e2,c;
        cin>>e1>>e2>>c;
        g.add(e1,e2,c);
    }
    g.prims();
    g.print();
    cout<<"\nwanna try again...??(y/n)\t";
    char c;
    cin>>c;
    if(c=='Y' || c=='y')goto label;
    return 0;
}