#include <stdio.h>
#include <stdlib.h>

int *getA();
int *getB();

char userChoice();

int main(void){
    printf("Operation menu\n");
    printf("    1.Add\n    2.Subtract\n");
    printf("    3.Scalar Multiply\n    4.Multiply two matrices\n");
    
    
    int *A=getA();
    int *B=getB();
    printf("%d", A[0][1]);
    free(A);
    free(B);
    printf("Thank you");
}

//marix addition
int addition();
//get user chioce
char userChoice(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    if(choice==1 || choice==2){
        int *A=getA();
        int *B=getB();
        
    }
    char repeat;
    printf("Do you want to repeat: (Y/N) \n");
    scanf("%c", &repeat);
    return repeat;

}
 
int *getA(){
    int row_A;
    int column_A;
    
    printf("Enter #rows and #columns of A: ");
    scanf("%d %d", &row_A, &column_A);
    printf("%d %d \n",row_A,column_A);
    
    int *matrix_A[row_A];
    for(int i=0;i<row_A;i++){
        matrix_A[i]=malloc(sizeof(int)*column_A);
    }
    
    printf("Enter elements of %d x %d matrix A\n", row_A, column_A);
    for(int i=0;i<row_A;i++){
        printf("%d entries of row %d: ",column_A, i+1);
        for(int j=0;j<column_A;j++){
            scanf("%d", &matrix_A[i][j]);
        }
    }
    printf("\nmatrix A\n");
    for(int i=0;i<row_A;i++){
        for(int j=0;j<column_A;j++){
        printf("    %d", matrix_A[i][j]);
        }
        printf("\n");
    }
    return *matrix_A;
}

int *getB(){
    int row_B;
    int column_B;
    
    printf("Enter #rows and #columns of B: ");
    scanf("%d %d", &row_B, &column_B);
    printf("%d %d \n",row_B,column_B);
    
    int *matrix_B[row_B];
    for(int i=0;i<row_B;i++){
        matrix_B[i]=malloc(sizeof(int)*column_B);
    }
    
    printf("Enter elements of %d x %d matrix B\n", row_B, column_B);
    for(int i=0;i<row_B;i++){
        printf("%d entries of row %d: ",column_B, i+1);
        for(int j=0;j<column_B;j++){
            scanf("%d", &matrix_B[i][j]);
        }
    }
    printf("\nmatrix B\n");
    for(int i=0;i<row_B;i++){
        for(int j=0;j<column_B;j++){
        printf("    %d", matrix_B[i][j]);
        };
        printf("\n");
    }
    return *matrix_B;
}
