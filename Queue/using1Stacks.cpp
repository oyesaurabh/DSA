#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;
class using1Stacks{
    stack<int> s;
    public:
    void enQueue(int);
    int deQueue();
};
void using1Stacks::enQueue(int x){
    s.push(x);
}
int using1Stacks::deQueue(){
    if(s.empty()){
        cout<<"Empty\n";
        return -1;
    }
    int x=s.top();
    s.pop();
    if(s.empty())
        return x;
    int item = deQueue();
    s.push(x);
    return item;
}

int main(){
    using1Stacks q;
    int f=1;
    do{
        cout<<"1.enQueue 2.deQueue 3.exit\n";
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
            cout<<q.deQueue()<<endl;
            break;
        case 3:
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