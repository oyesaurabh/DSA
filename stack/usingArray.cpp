#include<iostream>
using namespace std;
class stack{
    int size;
    int top;
    int *a;
    public:
    stack(int size){
        this->size=size;
        top=-1;
        a=new int[size];
    }
    void push(int);
    int pop();
    void display();
    int isFull();
    int isEmpty();
    int peek();
    int at(int);
};
int stack::peek(){
    if(top!=-1)
        return a[top];
    else return -1;
}
int stack::at(int p){
    if(p>top || p<0){
        cout<<"Invalid Index\n";return -1;}
    return a[p];
}
void stack::push(int x){
    if(top==size-1)
        cout<<"stack OVERFLOW\n";
    else
        a[++top]=x;    
}
int stack::pop(){
    if(top<=-1){
        cout<<"stack UNDERFLOW\n";
        return -1;
    }
    return a[top--];
}
void stack::display(){
    if(top==-1)
        cout<<"stack UNDERFLOW\n";
    else{
        cout<<"\n";
        for(int i=0;i<=top;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}
int stack::isFull(){
    return (top==size-1)?1:0;
}
int stack::isEmpty(){
    return (top==-1)?1:0;
}
int main(){
    int s;
    cout<<"SIZE: ";
    cin>>s;
    stack s1(s);
    int f=1,e;
    do{ 
        cout<<"1.push 2.pop 3.display 4.peek 5.At 6.exit\n";
        int e;
        cin>>e;
        switch (e)
        {
        case 1:
            if(s1.isFull())
                cout<<"stack OVERFLOW\n";
            else{
                int z;
                cin>>z;
                s1.push(z);
            }
            break;
        case 2:
            if(s1.isEmpty())
                cout<<"stack UNDERFLOW\n";
            else
                cout<<s1.pop()<<"\n";
            break;
        case 3:
            s1.display();
            break;
        case 4:
            cout<<s1.peek()<<"\n";
            break;
        case 5:
            cout<<"P: ";
            int p;
            cin>>p;
            cout<<s1.at(p)<<"\n";
            break;
        case 6:
            f=0;
            break;
        default:
            cout<<"Wrong Input\n";
            break;
        }

    }while(f);
    return 0;
}