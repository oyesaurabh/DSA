//WaiseHi
#include<bits\stdc++.h>
using namespace std;
struct node{
    node *left;
    int data;
    node *right;
    int height;
    node(int e){
        data=e;
        left=right=NULL;
        height=0;
    }
};
class AVL{
    public:
    node *root;
    AVL(){
        root=NULL;
    }
    node* insert(node*,int);
    void display();
};
int getHeight(node *t){
    if(!t)
        return 0;
    return t->height;
}
int getBalanceFactore(node* t){
    if(!t)
        return 0;
    int l=(t->left?t->left->height:0);
    int r=(t->right?t->right->height:0);
    return l-r;
}
void AVL::display(){
    cout<<"\nPREORDER:\n";
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* t=s.top();
        s.pop();
        cout<<t->data<<" ";
        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);
    }
    cout<<"\n";
}
node* LeftRotation(node* l){
    
}
node* AVL::insert(node* r,int e){
    //Recursive insertion BST 
    if(r==NULL)
        return new node(e);
    if(r->data >e)
        r->left=insert(r->left,e);
    else if(r->data < e)
        r->right=insert(r->right,e);
    else
        return r;
    
    //main logic
    int height=1+max(r->left->height,r->right->height);
    int balance=getBalanceFactore(r);


    return r;
}
int main(){
    //here
    AVL a;
    int n;
    cout<<"N: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    for (int i = 0; i < n; i++)
        a.root=a.insert(a.root,arr[i]);
    a.display();
    return 0;
}