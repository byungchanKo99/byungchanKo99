#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct StackNode{
    int data;
    struct StackNode* nextNode;
}StackNode;

typedef struct Stack{
    int maxSize;  //size 임의 조정 가능
    int curNode;
    StackNode headNode;
}Stack;

void push(Stack* S, int data);
StackNode* pop(Stack* S);
void show(Stack* S);
StackNode* top(Stack* S);
void delete(Stack* S);
int isEmpty(Stack* S);

int main(){
    Stack* singleStack = (Stack*)malloc(sizeof(Stack));
    StackNode* pNode = NULL;
    singleStack->maxSize = 10; //지금 만들어진 스택의 최대 노드 개수는 10
    singleStack->curNode = 0;
    printf("Push(10,20,30) called\n");
    push(singleStack,10);
    push(singleStack,20);
    push(singleStack,30);
    push(singleStack,10);
    push(singleStack,20);
    push(singleStack,30);
    push(singleStack,10);
    push(singleStack,20);
    push(singleStack,30);
    push(singleStack,10);
    push(singleStack,20);
    push(singleStack,30);
    show(singleStack);

    printf("Pop() called\n");
    pNode = pop(singleStack);

    if(pNode){//pNode의 값이 있다면
        free(pNode);
        show(singleStack);
    }

    printf("Top() called\n");
    pNode = top(singleStack);
    if(pNode){
        printf("Top node's data: %d\n",pNode->data);
    }
    else{
        printf("The Stack is currently empty\n");
    }
    show(singleStack);

    delete(singleStack);
    return 0;

}

void push(Stack* S, int data){
    if(S == NULL){
        printf("push() error \n");
        return;
    }
    if(S->curNode == S->maxSize){
        printf("push() error 2 : stack overflow\n");
        return;
    }
    StackNode* newNode = NULL, *tmpNode = NULL;
    newNode = (StackNode*)malloc(sizeof(StackNode));
    
    if(newNode == NULL){
        printf("push() error 3 : lack of memory\n");
        return;
    }

    //스텍 자료구조 노드들 이동.
    newNode->data = data;
    tmpNode = &(S->headNode);
    newNode->nextNode = tmpNode->nextNode;
    tmpNode->nextNode = newNode;
    
    S->curNode++;
    return;
}

void show(Stack* S){
    StackNode* tmpNode = NULL;
    tmpNode = S->headNode.nextNode;
    printf("show stack =====================\n");
    while(tmpNode != NULL){
        printf("[%d]\n",tmpNode->data);
        tmpNode = tmpNode->nextNode;
    }
}

StackNode* pop(Stack *S){
    StackNode * popNode = S->headNode.nextNode;
    S->headNode.nextNode = popNode->nextNode;
    popNode->nextNode = NULL;
    return popNode;
}

StackNode* top(Stack *S){
    StackNode * topNode = S->headNode.nextNode;
    return topNode;
}

void delete(Stack *S){
    while(S->headNode.nextNode){
        StackNode * tmpNode = S->headNode.nextNode;
        S->headNode.nextNode = tmpNode->nextNode;
        tmpNode->nextNode = NULL;
        free(tmpNode);
    }
    return;
}

int isEmpty(Stack *S){
    if(S->curNode == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}