#include<iostream>
#include<conio.h>
using namespace std;
class circularQueue{
    int size;
    int *a;
    int rear,front;
    public: 
    circularQueue(int size){
        this->size=size;
        rear=front=-1;
        a=new int[size];
    }
    void encircularQueue(int);
    void decircularQueue();
    int first();
    int last();
    void display();

};
void circularQueue::encircularQueue(int x){
    if( (rear+1)%size==front)
        cout<<"circularQueue full\n";
    else{
        if(front==-1)
            front++;
        rear=(rear+1)%size;
        a[rear]=x;
    }
}
void circularQueue::decircularQueue(){
        if(front==-1 )
            cout<<"circularQueue empty\n";    
        else if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%size;
    }
int circularQueue::first(){
    if(front==-1 )
        return -1;
    return a[front]; 
    }
int circularQueue::last(){
    if(front==-1 )
        return -1;
    return a[rear];
    }
void circularQueue::display(){
    if(front==-1 )
        cout<<"Empty";
    else if(front<=rear)
        for(int i=front;i<=rear;i++)
            cout<<a[i]<<" ";
    else{
        for(int i=front;i<=size-1;i++)
            cout<<a[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int s;
    cout<<"SIZE: ";
    cin>>s;
    circularQueue q(s);
    int f=1;
    do{
        cout<<"1.enQueue 2.deQueue 3.Display 4.first 5.last 6.exit\n";
        int c;
        cin>>c;
        switch (c)
        {
        case 1:
            int x;
            cin>>x;
            q.encircularQueue(x);
            break;
        case 2:
            q.decircularQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout<<q.first()<<"\n";
            break;
        case 5:
            cout<<q.last()<<"\n";
            break;
        case 6:
            f=0;
            break;
        default:
            cout<<"Invalid\n";
            break;
        }
        
    } while (f!=0);
    getch();
    return 0;
}
