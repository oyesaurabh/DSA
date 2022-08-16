#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
//trie node 
struct node{
    node *children[26];
    bool isterminal; // tell whether word is completed or not
    node(){
        isterminal=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};

//trie functions
class Trie{
    node *root;
    public:
    Trie(){
        root=new node();
    }
    //O(length of word)
    void insert(string word){
        node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]-'a'] == NULL)
                temp->children[word[i] - 'a']=new node();
            temp=temp->children[word[i] - 'a'];
        }
        temp->isterminal=1;
    }
    //O(len)
    bool search(string word){
        node *t=root;
        for(int i=0;i<word.size();i++){
            if(t->children[word[i]-'a'] == NULL)return 0;
            t=t->children[word[i] - 'a'];
        }
        return t->isterminal;
    }
    //O(len)
    bool startswith(string word){
        node *t=root;
        for(int i=0;i<word.size();i++){
            if(t->children[word[i]-'a']==NULL)return 0;
            t=t->children[word[i]-'a'];
        }
        return 1;
    }
};

//our main function
int main(){
    //here
    Trie t;
    t.insert("apps");
    t.insert("apple");
    cout<<t.startswith("app")<<" "<<t.search("app");
    getch();
    return 0;
}