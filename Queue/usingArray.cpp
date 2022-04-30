#include<iostream>
#include<conio.h>
using namespace std;
class Queue{
    int size;
    int *a;
    int rear,front;
    public:
    Queue(int size){
        this->size=size;
        rear=front=-1;
        a=new int[size];
    }
    void enQueue(int);
    void deQueue();
    int first();
    int last();
    void display();

};
void Queue::enQueue(int x){
    if(rear==size-1)
        cout<<"Queue full\n";
    else{
        if(front==-1)
            front++;
        
        a[++rear]=x;
    }
}
void Queue::deQueue(){
        if(front==-1 || front>rear)
            cout<<"Queue empty\n";    
        else
            front++;
    }
int Queue::first(){
    if(front==-1 || front>rear)
        return -1;
    return a[front]; 
    }
int Queue::last(){
    if(front==-1 || front>rear)
        return -1;
    return a[rear];
    }
void Queue::display(){
    if(front==-1 || front>rear)
        cout<<"Empty";
    else
        for(int i=front;i<=rear;i++)
            cout<<a[i]<<" ";
    cout<<"\n";
}
int main(){
    int s;
    cout<<"SIZE: ";
    cin>>s;
    Queue q(s);
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
            q.enQueue(x);
            break;
        case 2:
            q.deQueue();
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
