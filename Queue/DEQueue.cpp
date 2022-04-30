#include<iostream>
#include<conio.h>
using namespace std;
class DEQueue{
    int front,rear,*a;
    int size;
    public:
    DEQueue(int x){
        front=rear=-1;
        size=x;
        a=new int[size];
    }
    void insert_front(int);
    void insert_rear(int);
    void delete_front();
    void delete_rear();
    void display();
};
void DEQueue::insert_front(int x){
    if(front-1<0)
        cout<<"FULL\n";
    else
        a[--front]=x;
}
void DEQueue::insert_rear(int x){
    if(rear+1==size)
        cout<<"Full\n";
    else{
        if(front==-1)
            front++;
        a[++rear]=x;
    }
}
void DEQueue::delete_front(){
    if(front==-1)
        cout<<"Empty\n";
    else if(rear==front)
        rear=front=-1;
    else
        front++;
}
void DEQueue::delete_rear(){
    if(rear==-1)
        cout<<"Empty\n";
    else if(rear==front)
        rear=front=-1;
    else 
        rear--;
}
void DEQueue::display(){
    if(front==-1 || front>rear)
        cout<<"empty\n";
    else{
        for(int i=front;i<=rear;i++)
            cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int s;
    cout<<"Size\n";
    cin>>s;
    DEQueue d(s);
    int f=1;
    do{
        cout<<"\n1.insert_front 2.insert_rear 3.delete_front 4.delete_rear 5.display 6.exit\n";
        int c;
        cin>>c;
        switch (c)
        {
        case 1:{
            int x;
            cin>>x;
            d.insert_front(x);}
            break;
        case 2:{
            int x;
            cin>>x;
            d.insert_rear(x);}
            break;
        case 3:
            d.delete_front();
            break;
        case 4:
            d.delete_rear();
            break;
        case 5:
            d.display();
            break;
        case 6:
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