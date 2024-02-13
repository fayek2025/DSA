# include <bits/stdc++.h>
using namespace std;

struct que{
    struct node{
        char val;
        node* next;
    };
    node* head=NULL;
    node* tail=NULL;
    void enqueue(char x){
        node* newnode=new node();
        newnode-> val=x;
        newnode->next=NULL;
        if(tail==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    char dequeue(){
        if(head!=NULL){
            int x=head->val;
            head=head->next;
            return x;
        }
        return '*';
    }
    char peek(){
        if(head!=NULL){
            return head->val;
        }
        return '*';
    }
};

struct stac{
    struct node{
        char val;
        node* next;
    };
    node* head=NULL;
    void push(char x){
        node* newnode= new node();
        newnode->val=x;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    char pop(){
        char c=head->val;
        head=head->next;
        return c;
    }

};

void isPalindrom(){
    string str;
    cin>>str;
    int len=str.length();
    stac first;
    que last;
    for(int i=0; i<(len/2); i++){
        first.push(str[i]);
    }
    if(len&1){
        for(int i=(len/2)+1; i<len; i++){
            last.enqueue(str[i]);
        }
    }else{
        for(int i=(len/2); i<len; i++){
            last.enqueue(str[i]);
        }
    }
    while(first.head!=NULL && last.head!=NULL){
        if(first.pop()!=last.dequeue()){
            cout<<"not palindrom"<<endl;
            return;
        }
    }
    cout<<"palindrom"<<endl;
}

int main(){
    isPalindrom();
    return 0;
}