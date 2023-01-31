/*create linked list*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//creating node sturcture 
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
//change sturct node name to node
typedef struct node node;

//create linked list head
node* head=NULL;

int insertNewNode(int a);   //insertNewNode function declartion
node* createNewNode(int a); //createNewNode function declartion
void print();               //print function declartion
void printReverse();        //reverse print declartion 
int freelist();             //freelist function declartion     

int main(){
    insertNewNode(2);
    insertNewNode(4);
    insertNewNode(6);
    insertNewNode(8);
    
    printf("list: "); print();
    printf("reverse list: "); printReverse();
    
    freelist();
    return 0;
}

//free linked list 
int freelist(){
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        free(temp->prev);
    }
    return 0;
}

//insert new node to linked list 
int insertNewNode(int a){
    node* newNode = createNewNode(a);
    
    if(head==NULL){
        head = newNode;
        return 0;
    }
    newNode->next = head;
    head->prev=newNode;
    head=newNode;
    
    return 0;
}

//create new node
node* createNewNode(int a){
    //create new node in heap
    node* newNode = (node*)malloc(sizeof(node)); 
    //checking memory avalability
    if(newNode == NULL ){
        printf("error occured creating new node");
        return 1;
    }
    newNode->data=a;   //assign a to newNode data
    newNode->next=NULL; //set next to NULL 
    newNode->prev=NULL; //set prev to NULL
    
    return newNode; //return newNode address
}

//print linked list forward
void print(){
    node* temp = head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp=temp->next;
    }
}

//print linked list reverse
void printReverse(){
    node* temp = head;
    int i = 0;
    int arr[MAX_SIZE];
    //collecting data
    while(temp!=NULL){
        arr[i]=temp->data;
        temp=temp->next;
        ++i;
    }
    while(i!=0){
        printf("%d",arr[i-1]);
        --i;
    }
}
