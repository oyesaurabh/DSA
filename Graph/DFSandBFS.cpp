
#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class graph{
    int v;
    vector<int> *adj;
    public:
    graph(int v){
        this->v=v;
        adj=new vector<int>[v+1];
    }
    void addEdges(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int);
    void DFS(int);
};
	   
void graph::BFS(int s){
    vector<bool> vis(v+1,0);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while( !q.empty() ){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
void graph::DFS(int s){
    vector<bool> vis(v+1,0);
    stack<int> stack;
    stack.push(s);
    vis[s]=1;
    while (!stack.empty()){
        int s = stack.top();
        stack.pop();
        cout << s << " ";

        for (auto i :adj[s])
            if (!vis[i]){
                stack.push(i);
                vis[i]=1;
            }
    }
}
int main(){
    x:
    system("CLS");
    int v,e;
    cout<<"V and E\n";
    cin>>v>>e;

    graph g(v);

    cout<<"enter "<<e<<" edges\n";
    for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            g.addEdges(u,v);
        }
    int s;
    cout<<"enter starting Vertex\n";
    cin>>s;

    cout<<"BFS:\t";
    g.BFS(s);
    cout<<"\nDFS:\t";
    g.DFS(s);
    cout<<"\npress 'Y' to try again...\n";
    char c;
    cin>>c;
    if(tolower(c)=='y')
        goto x;
    return 0;
}