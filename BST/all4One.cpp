//WaiseHi
#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int e){
        data=e;
        left=right=NULL;
    }
};
class BST{
    public:
    node* root;
    BST(){
        root=NULL;
    }
    void in(node*);
    void insert(int);
    void search(int);
    node* deleteRecursively(node*,int);
};
void BST::in(node *r){
    if(r){
        in(r->left);
        cout<<r->data<<" ";
        in(r->right);
    }
}
void BST::insert(int e){
    node *n=new node(e);
    if(root==NULL){
        root=n;
        return;
    }
    node *t=NULL,*q=root;
    while(q){
        t=q;
        if(q->data > e)
            q=q->left;
        else if(q->data < e)
            q=q->right;
        else
            return;
    }
    if(t->data<e)
        t->right=n;
    else
        t->left=n;
}
void BST::search(int e){
    if(!root){
        cout<<"Empty\n";
        return;
    }
    node* n=root;
    while(n!=NULL){
        if(n->data < e)
            n=n->right;
        else if(n->data > e)
            n= n->left;
        else{
            cout<<"Found\n";
            return;
        }
    }
    cout<<"Not Found\n";
}
node* inorderSuccessor(node* r){
    node* curr=r;
    while(curr && curr->left!=NULL)
        curr=curr->left;
    return curr;
}
node* BST::deleteRecursively(node* r,int e){
    if(r==NULL)
        return NULL;
    if(r->data > e)
        r->left = deleteRecursively(r->left,e);
    else if(r->data < e)
        r->right=deleteRecursively(r->right,e);
    else{   
            //leaf node
            if(r->left == NULL && r->right==NULL)
                return NULL;
            //having one child
            else if(r->left==NULL){
                node* temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                node* temp=r->left;
                delete r;
                return temp;
            }
            //having more than 2 child
            else{
                node* temp=inorderSuccessor(r->right);
                r->data=temp->data;
                r->right=deleteRecursively(r->right,temp->data);
            }
    }
    return r;
}
int main(){
    //here
    BST b;
    int c;
    int f=1;
    while(f)
        {
        cout<<"\n1.Insert 2.deleteR 3.search 4.display 5.exit\n";
        cin>>c;
        switch(c){
            case 1:{
                int e;
                cout<<"E: ";
                cin>>e;
                b.insert(e);
                break;
            }
            case 2:
            {
                int e;
                cout<<"E: ";
                cin>>e;
                b.root=b.deleteRecursively(b.root,e);
                break;
            }
            case 3:{
                int e;
                cout<<"E: ";
                cin>>e;
                b.search(e);
                break;
            }
            case 4:
                b.in(b.root);
                break;
            case 5:
                f=0;
                break;
            default:
                cout<<"Invalid\n";
                break;
        }
    }
    getch();
    return 0;
}