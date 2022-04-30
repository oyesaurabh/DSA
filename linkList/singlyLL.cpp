#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node *next;
};
class LL{
    node *start=NULL,*last=NULL;
    public:
    void insertAtLast(int e){
        node *n;
        n=new node;
        n->data=e;
        n->next=NULL;
        if(start==NULL)
            last=start=n;
        else{node *t=start;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=n;
            last=n;
        }
    }
    node* getStart(){
        return start;
    }
    int isSorted(){
        if(start==NULL){
            cout<<"empty\n";
            getch();
            return 0;
        }
        else{
            node *t=start;
            while(t->next!=NULL && t->data<=t->next->data)
                t=t->next;
            if(t->next==NULL)
                return 1;
            else return 0;
        }
    }
    void insertAtFirst(int e){
        node *n;
        n=new node;
        n->data=e;
        n->next=start;
        start=n;
        
    }
    void insertAt(int p,int e){
        node *n;
        n=new node;
        n->data=e;
        n->next=NULL;
        if(p==0)
            insertAtFirst(e);
        else{
            node *t=start;
            while(t!=NULL && --p>=1)
                t=t->next;
            if(t==NULL){
                cout<<"OutOfRange\n";
                getch();
            }
            else{
                n->next=t->next;
                t->next=n;
            }
        }
    }
    void display(){
        if(start==NULL)
            cout<<"List is empty\n";
        else{
            node *t=start;
            while(t!=NULL){
                cout<<t->data<<" ";
                t=t->next;
            }
        }
    }
    void delFromLast(){
        if(start==NULL)
            printf("list is empty\n");
        else{
            node *t=start;
            if(t->next==NULL){
                cout<<"deleted : ";
                cout<<t->data;
                start=NULL;
            }
            else{
            while (t->next->next!=NULL)
                t=t->next;
                
            cout<<"deleted : ";
            cout<<t->next->data ;
            t->next=NULL;
            last=t;}
        }
    }
    void delFrom(int pos){
        if(start==NULL){
            printf("list is empty\n");
            getch();
        }
        else{
            if(pos==0){
                node *temp=start;
                start=start->next;
                delete temp;
            }
            else
            {
                node *p=start;
                node *q=NULL;
                while(pos-->0 && p!=NULL){
                    q=p;
                    p=p->next;
                }
                if(p==NULL){
                    cout<<"OutOfRange\n";
                    getch();}
                else{
                    q->next=p->next;
                    delete p;
                }
            }
        }
    }
    int countNodes(){        
        if(start==NULL){
            printf("list is empty\n");
            return 0;
        }
        int c=0;
        node *t=start;
        while(t!=NULL){
            c++;
            t=t->next;
        }
        return c;
    }
    int sum(){
        if(start==NULL)
            return -1;

        int s=0;
        node *t=start;
        while (t!=NULL)
        {
            s+=t->data;
            t=t->next;
        }
        return s;
    }
    void maxEle(){
        if(start==NULL)
            cout<<"list is empty \n";
        else{
            node *t=start;
            int max=t->data;
            int min=t->data;
            t=t->next;

            while(t!=NULL){
                if(t->data>max)
                    max=t->data;
                if(t->data<min)
                    min=t->data;
                t=t->next;
                
            }
            cout<<"Max: "<<max<<"\nMin: "<<min;   
        }
    }
    int search(int e){
        if(start==NULL){
            cout<<"list is empty \n";
            return -1;
        }
        else{
            int ind=0;
            node *t=start;
            while(t!=NULL){
                if(t->data==e)
                    return ind;
                t=t->next;
                ind++;
            }
            return -1;
        }
    }
    void reverseUsingArray(){
        if(start==NULL)
            cout<<"empty\n";
        else{
            int a[countNodes()]={0};
            node *t=start;
            int i=0;
            while(t!=NULL){
                a[i++]=t->data;
                t=t->next;
            }
            t=start;
            i--;
            while(t!=NULL){
                t->data=a[i--];
                t=t->next;
            }
        }
    }
    void reverseUsingLinks(){
        if(start==NULL)
            cout<<"empty\n";
        else{
            node *p,*q,*r;
            p=start;
            q=NULL;
            r=NULL;
            while(p!=NULL){
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            start=q;
        }
    }
    void reverseUsingRecursion(node *p,node *q){
        if(start==NULL)
            cout<<"empty\n";
        else{
            if(p!=NULL){
                reverseUsingRecursion(p->next,p);
                p->next=q;
            }
            else
                start=q;
        }
    }
    void removeDuplicates(){
        if(start==NULL)
            cout<<"empty\n";
        else if(!isSorted())
            cout<<"NotSorted\n";
        else{
            node *p=start;
            node *q=start->next;
            while(q!=NULL){
                if(p->data!=q->data){
                    p=q;
                    q=q->next;
                }
                else{
                    p->next=q->next;
                    delete q;
                    q=p->next;
                }
            }
        }
    }
    void searchUsingMove2Head(int e){
        if(start==NULL)
            cout<<"empty\n";
        else{int f=0;
            node *p,*tail;
            tail=p=start;
            while(p!=NULL){
                if(p->data==e){
                    f=1;
                    cout<<"Found\n";
                    if(p!=start)
                    {
                        tail->next=p->next;
                        p->next=start;
                        start=p;
                        break;
                    }
                }
                tail=p;
                p=p->next; 
            }if(!f)
                cout<<"NotFound\n";
        }
    }

};
int main(){
    LL l1;
    int c='y';
    while(c=='y' || c=='Y'){
        system("CLS");
        int q,e,p;
        cout<<"\n1.insertAtFirst\n2.insertAt\n3.insertAtLast\n\n5.deleteFromFirst\n6.DeleteAt\n7.DeleteFromLast\n\n8.display\n9.number of elements\n10.Sum\n11.Max&Min\n12.isSorted\n13.removeDuplicates\n\n14.search\n15.searchUsingMove2Head\n\n16.reverseUsingArray\n17.reverseUsingLinks\n18.reverseUsingRecursion\n\n19.exit\n*************************\n";
        cin>>q;
        switch (q)
        {
        case 3:
            cout<<"enter element : ";
            cin>>e;
            l1.insertAtLast(e);
            break;
        case 1:
            cout<<"enter element : ";
            cin>>e;
            l1.insertAtFirst(e);
            break;
        case 2:
            cout<<"enter e: ";
            cin>>e;
            cout<<"enter position: ";
            cin>>p;
            l1.insertAt(p,e);
            break;
        case 5:
            l1.delFrom(0);
            break;
        case 6:
            cout<<"Position: ";
            cin>>p;
            l1.delFrom(p);
            break;
        case 8:
            cout<<"\nelements are\n";
            l1.display();
            getch();
            break;
        case 16:
            l1.reverseUsingArray();
            l1.display();
            getch();
            break;
        case 17:
            l1.reverseUsingLinks();
            l1.display();
            getch();
            break;
        case 18:
            l1.reverseUsingRecursion(l1.getStart(),NULL);
            l1.display();
            getch();
            break;
        case 19:
            c='n';
            break;
        case 13:
            l1.removeDuplicates();
            l1.display();
            getch();
            break;
        case 12:
            if(l1.isSorted())
                cout<<"Yes\n";
            else
                cout<<"No\n";
            getch();
            break;
        case 15:
            cout<<"enter E to search:\n";
            cin>>e;
            l1.searchUsingMove2Head(e);
            getch();
            break;
        case 7:
            l1.delFromLast();
            break;
        case 9:
            cout<<"number of elements: "<<l1.countNodes()<<endl;
            getch();
            break;
        case 10:
            if(l1.sum()==-1)
                cout<<"empty \n";
            else
                cout<<"Sum : "<<l1.sum();
                getch();
                break;
        case 11:
            l1.maxEle();
            getch();
            break;
        case 14:
            cout<<"enter element to search..";
            cin>>e;
            if(l1.search(e)!=-1)
                cout<<"element FOUND at index: "<<l1.search(e)<<endl;
            else
                cout<<"Not Present\n";
            getch();
            break;
        default:
            cout<<"Give Input properly ploxxx\n";
            getch();
            break;
        }

    }

    getch();
    return 0;
}