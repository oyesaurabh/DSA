//WaiseHi
#include<bits\stdc++.h>
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
    node *root;
    public:
    void generate(vector<int> &a){
        stack<node*> s;
        int i=0;
        root=new node(a[i++]);
        node* p=root;
        int n=a.size();
        while(i<n){
            if(a[i]<p->data){
                node* t=new node(a[i++]);
                p->left=t;
                s.push(p);
                p=t;
            }
            else{
                if(a[i]>p->data && a[i]< (s.empty()?INT_MAX:s.top()->data) ){
                    node* t=new node(a[i++]);
                    p->right=t;
                    p=t;
                }
                else{
                    p=s.top();
                    s.pop();
                }
            }
        }
    }
    void inorder(){
        stack<node*> s;
        node* t=root;
        while(t || !s.empty() ){
            if(t){
                s.push(t);
                t=t->left;
            }
            else{
                t=s.top();
                s.pop();
                cout<<t->data<<" ";
                t=t->right;
            }
        }
    }

};
int main(){
    //here
    int n;
    cout<<"N: ";
    cin>>n;
    vector<int> a;
    cout<<"enter PreOrder:\t";
    for(int i=0;i<n;i++){
        int e;cin>>e;
        a.push_back(e);
    }
    BST b;
    b.generate(a);
    cout<<"InOrder\t:";
    b.inorder();
    getch();
    return 0;
}