#include<iostream>
#include<conio.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
class BST{

int i=0;
public:
node* fun(vector<int> &p,  vector<int> &in,  int s,   int e,  unordered_map<int,int> &m){
        if(s>e)
            return NULL;
        int ele=p[i++];
        node* r=new node(ele);
        int index=m[ele];
        r->left=fun(p,in,s,index-1,m);
        r->right=fun(p,in,index+1,e,m);
        
        return r;
}
node* buildTree(vector<int>& p, vector<int>& in) {
        int i=0;
        unordered_map<int,int> m;
        for(int i=0;i<in.size();i++)
            m[in[i]]=i;
        return fun(p, in, 0, in.size()-1, m);
}
void postOrder(node* r){
    if(r==NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    cout<<r->data<<" ";
}
};
int main(){
    int n;
    cout<<"N: ";
    cin>>n;
    vector<int> pre,in;
    cout<<"PreOrder:\t";
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        pre.push_back(e);
    }
    cout<<"InOrder:\t";
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        in.push_back(e);
    } 
    BST b;
    node *root=b.buildTree(pre,in);
    
    cout<<"\nPostOrder:\t";
    b.postOrder(root);
    getch();
return 0;
}