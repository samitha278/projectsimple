#include <stdio.h>
#include <string.h>

int hash_function(char string[]); //hash function declartion

//create node structure
typedef struct node{
    char name[100];
    struct node* next;
}node;

//create hash table
node* hashtable[26];

int main(){
    //open file
    FILE* myfile;
    myfile = fopen("//path", "r");
    //check file's avalability
    if(myfile==NULL){
        printf("error occured while opening file");
        return 1;
    }
    //read file
    char ch[100];
    int read_line = fscanf(myfile,"%[^\n]", ch);
    //check read_line
    if(read_line==EOF){
        printf("error occured while reading file");
        return 1;
    }
    //close file
    int ele = fclose(myfile);
    //ckeck ele
    if(ele<=0){
        printf("error occured while reading file");
        return 1;
    }
    
    //create node for ch in heap
    node* n = malloc(sizeof(node));
    //ckeck malloc avalability
    if(n==NULL){
        printf("error occured creating node");
        return 1;
    }
    n->name=ch;    //assign string to node->name
    n->next=NULL;  //assign NULL to next node's address
    
    //get hash code
    int key = hash_function(ch);
    
    //linking node to hashtable
    hashtable[key]=n;
    
    return 0;
}
//create hash function
int hash_function(char string[]){
    int sum = 0;
    for(int i=0;string[i]!='\0';i++){
        sum+=string[i];
    }
    return sum%26;
}
