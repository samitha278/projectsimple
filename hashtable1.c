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
    myfile = fopen("//path", "rb");
    //check file's avalability
    if(myfile==NULL){
        printf("error occured while opening file");
        return 1;
    }
    
    char ch[100];
    //read file line by line 
    while((fgetc(ch, sizeof(ch),myfile))!=EOF){ 

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

        //assign NULL to hashtable elements
        for(int j=0;j<26;j++){
            hashtable[j]=NULL;
        }

        //linking node to hashtable
        if(hashtable[key]==NULL){
            hashtable[key]=n;
        }else{
            n->next=hashtable[key];
            hashtable[key]=n;
        }
    }
    
    //close file
    int ele = fclose(myfile);
    //ckeck ele
    if(ele<=0){
        printf("error occured while reading file");
        return 1;
    }
    
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
