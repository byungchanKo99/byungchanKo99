#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;



void insertTreeNode(Node** node, int value);
void printTreePreorder(Node* node);
void printTreeInorder(Node* node);
void printTreePostorder(Node* node);

int main(){
    Node* pParentNode = NULL;
    insertTreeNode(&pParentNode, 4);
    insertTreeNode(&pParentNode, 2);
    insertTreeNode(&pParentNode, 6);
    insertTreeNode(&pParentNode, 1);
    insertTreeNode(&pParentNode, 3);
    insertTreeNode(&pParentNode, 5);
    insertTreeNode(&pParentNode, 7);

    printf("Preorder : \n");
    printTreePreorder(pParentNode);

    printf("\nInorder : \n");
    printTreeInorder(pParentNode);

    printf("\nPostorder : \n");
    printTreePostorder(pParentNode);

    printf("\n");
    
    return 0;

}

void insertTreeNode(Node** bt, int value){
    if((*bt) == NULL){
        (*bt) = (Node*)malloc(sizeof(Node));
        (*bt)->data = value;
        (*bt)->left = NULL;
        (*bt)->right = NULL;
    }
    //만약에 내가 넣고자 하는 값이 현재 bt가 가리키고 있는 노드의 값보다 큰 경우 -> 오른쪽 이동
    else if((*bt)->data < value){
        insertTreeNode((&(*bt)->right), value);
    }
    else if((*bt)->data > value){
        insertTreeNode(&((*bt)->left),value);
    }
    else{
        printf("insertion error : same value");
        return;
    }
}

void printTreeInorder(Node* bt){
    //Left->Visit(Root)->Right
    //Hint : 재귀함수 사용
    if(bt){
        printTreeInorder(bt->left);
        printf("[%d] ", bt->data);
        printTreeInorder(bt->right);
    }
}

void printTreePostorder(Node* bt){
    //Left->Right->Visit(Root)
    //Hint : 재귀함수 사용
    if(bt){
        printTreePostorder(bt->left);
        printTreePostorder(bt->right);
        printf("[%d] ", bt->data);
    }
}

void printTreePreorder(Node* bt){
    //Visit(Root)->Left->Right
    //Hint : 재귀함수 사용
    if(bt){
        printf("[%d] ", bt->data);
        printTreePreorder(bt->left);
        printTreePreorder(bt->right);
    }
}