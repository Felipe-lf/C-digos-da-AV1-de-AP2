#include<stdio.h>
#include<stdlib.h>

#define stack_size  10

int stack[10];
int pos =0;

void push(int value){
    if(pos >= 10){
        printf("\nThe pile is full");
    }
    else
    stack[pos] = value;
    pos++;
}

int pop (void){
    int remove = --pos;
    int takeTopValue = stack[remove];
    stack[remove] = 0;
    return(takeTopValue);
}

int pileSize(void){

    if (pos == 0){
        empty();
        printf("\nThe stack size is: 0\n");
        system("pause");
    }

    return pos;
}

int topElement(void){
    int aux = pos;
    aux = aux-1;
    return stack[aux];
}

void empty(void){
    if (pos == 0){
        printf("\nThe stack is empty\n");
    }
    else
        printf("\n The stack is not empty");
}

int main(){
    int n;
    
    for (int i = 0; i < 10; i ++){
        printf("\nPlease, add int number: ");
        scanf("\n%d",&n);
        
        if(n%2 == 0){
            push(n);
        } 
        else
            pop();
    }

    printf("\n The stack is this: ");

    for (int j = 9; j >= 0; j--){
        printf("\n%d", stack[j]);
    }

    printf("\n The stack size is: %d",pileSize());

    printf("\n Removing the elements....");

    for(int k = 0; k <= stack_size; k++){
    printf("\nElement %d has been removed.",pop());
        for (int j = stack_size - 1; j >= 0; j--){
            printf("\n %d", stack[j]);
        }

        printf("\n The stack size is: %d",pileSize());

    }

    return 0;
    
}