#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct Node{
    int data;
    struct Node* nextNode;
}Node;

typedef struct LinkedList{
    int curCount; //현재 리스트에 들어있는 Node의 개수
    Node headNode; // 리스트의 시작 Node
}LinkedList;

//ADT of Linked List

int addNode(LinkedList* pList, int pos, int data);
int removeNode(LinkedList* pList, int pos);
void showNode(LinkedList* pList);
int isEmpty(LinkedList* pList);
int findPos(LinkedList* pList, int data);
void makeEmpty(LinkedList* pList);

int main(){
    int pos;
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->curCount = 0;
    linkedList->headNode.nextNode = NULL;

    printf("---showNode\n");
    showNode(linkedList);
    addNode(linkedList,0,10);
    addNode(linkedList,1,20);
    addNode(linkedList, 5, 10);
    addNode(linkedList,2,30);
    addNode(linkedList,1,50);
    printf("---showNode\n");
    showNode(linkedList);

    removeNode(linkedList, 1);
    printf("---showNode\n");

    showNode(linkedList);

    pos = findPos(linkedList, 30);
    printf("the location of node with data '30' : %d\n",pos);

    makeEmpty(linkedList);
    printf("---showNode\n");

    showNode(linkedList);

    return 0;
}

void showNode(LinkedList* pList){
    int i = 0;
    Node* curNode = pList->headNode.nextNode;
    while(curNode){
        printf("%dth Node data: %d\n", i, curNode->data);
        curNode = curNode->nextNode;
        i += 1;
    }
}

int isEmpty(LinkedList* pList){
    if(pList->headNode.nextNode == NULL){
        return TRUE;
    }
    return FALSE;
}

int removeNode(LinkedList* pList, int pos){
    if(pList == NULL){
        printf("removeNode() error1 \n");
        return FALSE;
    }
    if(pos > pList->curCount - 1){
        return FALSE;
    }
    int i = 0;
    Node * pTmpNode = NULL, *pTargetNode = NULL;
    pTmpNode = &(pList->headNode);
    for(i = 0; i< pos; i++){ // pos - 1 위치
        pTmpNode = pTmpNode -> nextNode;
    }
    pTargetNode = pTmpNode->nextNode;
    pTmpNode->nextNode = pTargetNode->nextNode;
    free(pTargetNode);
    pList->curCount -= 1;
    return TRUE;
}

int findPos(LinkedList* pList, int data){
    if(pList == NULL){
        printf("addNode() error1 \n");
        return FALSE;
    }
    int i = 0;
    Node* curNode = pList->headNode.nextNode;
    while(curNode){
        if(curNode->data == data){
            return i;
        }
        curNode = curNode->nextNode;
        i += 1;
    }
    return FALSE;

}

void makeEmpty(LinkedList* pList){
    //    while(pList->curCount > 0){
    //        removeNode(pList, pList->curCount -1);
    //    }

    //    Node * curNode =NULL, *nextNode = NULL;
    //    curNode = pList->headNode.nextNode;
    //    while(curNode){
    //        nextNode = curNode->nextNode;
    //        free(curNode);
    //        pList->curCount -= 1;
    //        curNode = nextNode;
    //    }

    while(!isEmpty(pList)) {
        Node* deleteNode = pList->headNode.nextNode;
        pList->headNode.nextNode = deleteNode->nextNode;
        free(deleteNode);
        pList->curCount -= 1;
    }
}



int addNode(LinkedList* pList, int pos, int data){
    int i = 0;
    Node* pNewNode = NULL, *pTmpNode = NULL;
    if(pList == NULL){
        printf("addNode() error1 \n");
        return FALSE;
    }
    if(pos < 0 || pos > pList->curCount){
        printf("addNode() error2 추가 범위 초과 \n");
        return FALSE;
    }

    pNewNode = (Node*)malloc(sizeof(Node));
    if(!pNewNode){
        printf("addNode() error3 \n");
        return FALSE;
    }

    pTmpNode = &(pList->headNode);
    for(i = 0; i<pos; i++){
        pTmpNode = pTmpNode -> nextNode;
    }
    pNewNode ->nextNode = pTmpNode-> nextNode;
    pTmpNode->nextNode = pNewNode;
    pNewNode->data = data;
    pList->curCount++;
    return TRUE;
}