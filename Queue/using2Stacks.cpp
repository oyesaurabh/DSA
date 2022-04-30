#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;
class using2Stacks{
    stack<int> s1,s2;
    public:
    void enQueue(int);
    int deQueue();
};
void using2Stacks::enQueue(int x){
    s1.push(x);
}
int using2Stacks::deQueue(){
    int x;
    if(s2.empty()){
        if(s1.empty()){
            cout<<"Empty\n";
            return -1;
        }
        else{
            while(!s1.empty()){
                s2.push( s1.top() );
                s1.pop();
            }
        }
    }
    x=s2.top();
    s2.pop();
    return x;
}

int main(){
    using2Stacks q;
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