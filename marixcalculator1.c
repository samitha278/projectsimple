#include <stdio.h>
#include <stdlib.h>

int *getmatrix(int row,int column);
int userChoice();
int addition(int *A,int *B);
int smultiply(int scalar,int *A);
int multiply(int *A,int *B);
int subtract(int *A,int *B);
int rA,cA;  //row_A , column_A
int rB,cB;  //row_B , column_B

int main(void){
    printf("Operation menu\n");
    printf("    1.Add\n    2.Subtract\n");
    printf("    3.Scalar Multiply\n    4.Multiply two matrices\n");
    
    userChoice();
}

int addition(int *A,int *B){
    int M[rA][cA];     //because rA==rB & cA==cB
    for(int i=0;i<rA;i++){
        for(int j=0;j<cA;j++){
            M[i][j]=A[i*cA+j]+B[i*cB+j];
            printf(" %d    ", M[i][j]);
        }        
        printf("\n");
    }
    
    
    
}
int subtract(int *A,int *B){
    
}

int multiply(int *A,int *B){
    
}

int smultiply(int scalar,int *A){
    
}

//get user chioce
int userChoice(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    int *A,*B; 
    printf("Enter number #rows and #columns of A: ");
    scanf("%d %d", &rA, &cA);
    A=getmatrix(rA,cA);
    
    if(choice==1 || choice==2 || choice==4){
        printf("Enter number #rows and #columns of B: ");
        scanf("%d %d", &rB, &cB);
        B=getmatrix(rB,cB);
        
        if(choice==1){
            addition(A,B);
        }else if(choice==2){
            subtract(A,B);
        }else{
            if(cA!=rB){
                printf("error! Invalid input (must equal A columns & B rows)");
                return 1;
            }
            multiply(A,B);
        }
    }else if(choice==3){
        int scalar;
        printf("Enter scalar: ");
        scanf("%d", &scalar);
        
        smultiply(scalar,A);
    }else{
        printf("error! Invalid input");
        return 1;
    }
    
    free(A);
    free(B);
    
    int repeat;
    printf("Do you want to repeat (if Yes-1/if No-0): \n");
    scanf("%c", &repeat);
    if(repeat==1)
        userChoice();
    else{
        printf("thank you");
        return 0;
    }
}
 
int *getmatrix(int row,int column){
    
    if(row<0 || column<0){
        printf("Error! enter valid inputs");
        return NULL;
    }
    
    int elements=row*column;
    int *matrix=(int *)malloc(sizeof(int)*elements);
    if(matrix==NULL){
        printf("Error occured creating matrix");
        return NULL;
    }
    
    printf("Enter elements of %d x %d matrix\n", row, column);
    for(int i=0;i<row;i++){
        printf("%d entries of row %d: ",column, i+1);
        for(int j=0;j<column;j++){
            scanf("%d", &matrix[i*column+j]);
        }
    }
    printf("\nmatrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
        printf("    %d", matrix[i*column+j]);
        }
        printf("\n");
    }
    return matrix;
}
