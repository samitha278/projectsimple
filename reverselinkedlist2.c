/*reverse linked list*/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;               //create node structure  

node *head=NULL;     //head of linked list 
int i = 0;

node *createNewNode(int x){
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode==NULL){
        printf("error occured creating new node");
        return NULL;
    }
    newNode->data = x;
    newNode->next = NULL;
    
    return newNode;
}                           //create new node 

int insertNewNode(int x){
    node *newNode = createNewNode(x);
    if(head==NULL){
        head = newNode;
        return 0;
    }
    newNode->next = head;
    head = newNode;
    return 0;
}                           //insert new node to l.list                

node *getLastNode(){
    if(head==NULL)
        return NULL;
    node *last=head;
    while(last->next!=NULL){
        last=last->next;
        i++;
    }
    return last; 
}                           //get last node address

int swap(node *k,node *l){
    node *temp = k;
    k=l;
    l=temp;
    return 0;
}

int reverselist(){
    if(head==NULL || head->next==NULL)
        return 1;
    node *temp=getLastNode();
    
    node *ptr[i];
    for(int j=0,n=i/2;j<n;j++){
        swap(ptr[j],ptr[n-1-j]);
    }
    head=temp;
    return 0;
}                           //reverse linked list                

int print(){
    if(head==NULL)
        return 0;
    node *temp=head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp=temp->next;
    }
    return 0;
}                           //print linked list

int main(){
    insertNewNode(2);        
    insertNewNode(5);
    insertNewNode(7);
    insertNewNode(8);
    print();
    reverselist();
    print();

    return 0;
}
