#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int data;
    node *next;
};
class Queue{
    node *rear,*front;
    public:
    Queue(){
        rear=front=NULL;
    }
    void deQueue();
    void enQueue();
    void display();

};
void Queue::enQueue(){
    node *n = new node;
    int x;
    cin>>x;
        n->data=x;
        n->next=NULL;
        if(front==NULL)
            front=rear=n;
        else{
            rear->next=n;
            rear=rear->next;
        }
}
void Queue::deQueue(){
    if(front==NULL)
        cout<<"Empty\n";
    else{
        node *temp=front;
        front=front->next;
        delete temp;
    }
}
void Queue::display(){
    if(front==NULL)
        cout<<"Empty\n";
    else{
        node *t=front;
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
        }
    }
}
int main(){
    Queue s;
    int f=1;
    do{
        cout<<"\n1.enQueue 2.deQueue 3.Display 4.exit\n";
        int c;
        cin>>c;
        switch (c)
        {
        case 1:
            s.enQueue();
            break;
        case 2:
            s.deQueue();
            break;
        case 3:
            s.display();
            break;
        case 4:
            f=0;
            break;
        default:
            cout<<"Invalid\n";
            break;
        }
    }while(f);
    getch();
    return 0;
}