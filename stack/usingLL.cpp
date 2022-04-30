#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class stack{
    node *top=NULL;
    public:
    void push(int);
    int pop();
    void display();
    int isEmpty();
    int peek();
    int at(int);
};
int stack::at(int p){
    if(isEmpty())
        return -1;
    node *t=top;
    for(int i=0;t!=NULL&&i<p;i++)
        t=t->next;
    if(t!=NULL)
        return t->data;
    else
        return -1;
}
int stack::peek(){
    if(top==NULL)
        return -1;
    return top->data;
}
void stack::push(int x){
    node *p = new node;
    if(p==NULL)
        cout<<"stack OVERFLOW\n";
    else{
        p->data=x;
        p->next=top;
        top=p;
    }
}
int stack::pop(){
    if(top==NULL)
        return -1;
    int x=top->data;
    node *temp=top;
    top=top->next;
    delete temp;
    return x;
}
void stack::display(){
    if(top==NULL)
        cout<<"EMPTY\n";
    else{
        node *t=top;
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;}
    }cout<<"\n";
}
int stack::isEmpty(){
    return (top==NULL)?1:0;
}
int main(){
    stack s;
    int f=1;
    do{
        cout<<"1.push 2.pop 3.display 4.peek 5.At 6.exit\n";
        int c;
        cin>>c;
        switch (c)
        {
        case 1:
            int e;
            cin>>e;
            s.push(e);
            break;
        case 2:
            if(s.isEmpty())
                cout<<"EMPTY\n\n";
            else
                cout<<s.pop()<<"\n";
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout<<s.peek()<<"\n";
            break;
        case 5:
            int p;
            cin>>p;
            cout<<s.at(p)<<endl;
            break;
        case 6:
            f=0;
            break;
        default:
            cout<<"WRONG INPUT\n";
            break;
        }

    }while(f);
    return 0;
}