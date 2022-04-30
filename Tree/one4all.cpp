#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
void insert(node *n,int x){
    n->data=x;
    n->left=n->right=NULL;
}
class Tree{
    public:
    node *root;
    Tree(){
        root=NULL;
    }

    void create();
    void preOrder();
    // void postOrder1stack();
    void postOrder2stack();
    void InOrder();
    void levelOrder();

    int numberOfNodes(node*);
    int sum(node*);
    int leaf(node*);
    int degree1(node*);
    int degree2(node*);
    int degree1and2(node*);
};
int Tree::numberOfNodes(node* r){
    if(r==NULL)
        return 0;
    int left=numberOfNodes(r->left);
    int right=numberOfNodes(r->right);
    return left + right +1;
}
int Tree::degree1(node* r){
    if(r==NULL)
        return 0;
    int x=degree1(r->left);
    int y=degree1(r->right);
    if( (!r->left && r->right) || (!r->right && r->left) )
        return x+y+1;
    else
        return x+y;
}
int Tree::degree2(node* r){
    if(r==NULL)
        return 0;
    int x=degree1(r->left);
    int y=degree1(r->right);
    if( r->left && r->right )
        return x+y+1;
    else
        return x+y;
}
int Tree::degree1and2(node* r){
    if(r==NULL)
        return 0;
    int x=degree1(r->left);
    int y=degree1(r->right);
    if( r->left || r->right )
        return x+y+1;
    else
        return x+y;
}
int Tree::leaf(node *r){
    if(r==NULL)
        return 0;
    int x=leaf(r->left);
    int y=leaf(r->right);
    if(r->left==NULL && r->right==NULL)
        return x+y+1;
    else
        return x+y;
}
int Tree::sum(node *r){
    if(r==NULL)
        return 0;
    int x=sum(r->left);
    int y=sum(r->right);
    return (x+y+r->data);
}
void Tree::create(){
    cout<<"Root data\n";
    int x;
    cin>>x;
    root=new node();
    insert(root,x);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *t=q.front();
        q.pop();
        cout<<"enter left value of "<<t->data<<"\n";
        cin>>x;
        if(x!=-1){
            node *n=new node();
            insert(n,x);
            t->left=n;
            q.push(n);
        }
        cout<<"enter Right value of "<<t->data<<"\n";
        cin>>x;
        if(x!=-1){
            node *n=new node();
            insert(n,x);
            t->right=n;
            q.push(n);
        }
    }
}
void Tree::preOrder(){
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *n = s.top();
        s.pop();
        cout << n->data << " ";
        if (n->right)
            s.push(n->right);
        if (n->left)
            s.push(n->left);
    }
}
void Tree::InOrder(){
    stack<node*> s;
    node *t=root;
    while (t || !s.empty())
    {
        if (t){
            s.push(t);
            t = t->left;
        }
        else{
            t = s.top();
            s.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}
void Tree::postOrder2stack(){
    //using 2 stack
    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        node *t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left)
            s1.push(t->left);
        if(t->right)
            s1.push(t->right);
    }
    while(!s2.empty()){
        cout<<(s2.top())->data<<" ";
        s2.pop();
    }
}
// void Tree::postOrder1stack(){

// }
void Tree::levelOrder(){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *t=q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }
}
int main(){
    Tree t;
    t.create();
    cout << "\nPreOrder:\n";
    t.preOrder();
    cout << "\nInOrder:\n";
    t.InOrder();
    // cout << "\nPostOrder using 1 stack:\n";
    // t.postOrder1stack();
    cout << "\nPostOrder using 2 stack:\n";
    t.postOrder2stack();
    cout << "\nLevelOrder:\n";
    t.levelOrder();
    cout<<"\n\nNumberOfNodes: "<<t.numberOfNodes(t.root);
    cout<<"\nSum: "<<t.sum(t.root);
    cout<<"\nNumberOf Leaf Nodes(degree 0): "<<t.leaf(t.root);
    cout<<"\ndegree 1: "<<t.degree1(t.root);
    cout<<"\ndegree 2: "<<t.degree2(t.root);
    cout<<"\ndegree 1 and 2: "<<t.degree1and2(t.root)<<"\n";
    getch();
    return 0;
}