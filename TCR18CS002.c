


#include <stdio.h>
#include <stdlib.h>

typedef struct stackk{
    int DATA;
    struct stackk* p;
}stack;

stack *topA=NULL,*topB=NULL,*top;
  
void push(int DATA,int num){
    stack* x=(stack*)malloc(sizeof(stack));
    if(x==NULL){
        printf("Overflow; Queue is full\n");
        return;
    }
    else{
        if(num==1){
            x->DATA=DATA;
            x->p=topA;
            topA=x;
        }
        else if(num==2){
            x->DATA=DATA;
            x->p=topB;
            topB=x;
        }
        else if(num==3){
            x->DATA=DATA;
            x->p=top;
            top=x;
        }
    }
}

int pop(int num){
    int n;
    stack* x=NULL;
    if(num==1){
        x=topA;
        topA=topA->p;
    }
    else if(num==2){
        x=topB;
        topB=topB->p;
    }
    else if(num==3){
        x=top;
        top=top->p;
    }
    n=x->DATA;
    free(x);
    return n;
}

void display(){
    top=NULL;
    if(topA==NULL && topB==NULL){
        printf("Underflow; Queue is empty\n");
        return;
    }
    stack *x;
    x=topB;
    printf("Stack: ");
    while(x!=NULL){
        printf("%d ",x->DATA);
        x=x->p;
    }
    x=topA;
    while(x!=NULL){
        push(x->DATA,3);
        x=x->p;
    }
    while(top!=NULL){
        printf("%d ",pop(3));
    }
    printf("\n");
}

void enqueue(int DATA){
    push(DATA,1);
    display();
}

void dequeue(){
    int DATA;
    if(topA==NULL && topB==NULL){
        printf("Underflow; Queue is empty\n");
        return;
    }
    if(topB==NULL){
        while(topA!=NULL){
            DATA=pop(1);
            push(DATA,2);
        }
    }
    DATA=pop(2);
    printf("Data dequeued: %d\n",DATA);
    display();
}

int main(int argc,char* argv[]){
    char A[20];
    int DATA;
    FILE* filePtr=fopen(argv[1],"r");
    if(filePtr==NULL){
        printf("Failed to open the file!\n");
        exit(0);
    }
    while(fgets(A,20,filePtr)!=NULL){
        DATA=0;
        if(A[0]=='I'){
            for(int i=1;A[i]!='\0';i++)
                if(A[i]>='0' && A[i]<='9')
                    DATA=DATA*10+A[i]-'0';
            enqueue(DATA);
        }     
        else if(A[0]=='D'){
            dequeue();
        }
        else{
            printf("Invalid Command.\n");
        }
    }
    fclose(filePtr);
    return 0;
}



