
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;



void insertTreeNode(Node** bt, int value);
void printTreePreorder(Node* bt);
void printTreeInorder(Node* bt);
void printTreePostorder(Node* bt);
Node* searchTreeNode(Node* bt, int value);
Node* searchTreeParentNode(Node* bt, int value);
//과제(~9/13)
void deleteTreeNode(Node** bt, int value);
void copyTreeNode(Node* src, Node** dst);
int compareTwoTree(Node* t1, Node* t2);

int main(){
    Node* pParentNode = NULL;
    Node* cParentNode = NULL;
    insertTreeNode(&pParentNode, 4);
    insertTreeNode(&pParentNode, 2);
    insertTreeNode(&pParentNode, 6);
    insertTreeNode(&pParentNode, 1);
    insertTreeNode(&pParentNode, 3);
    insertTreeNode(&pParentNode, 5);
    insertTreeNode(&pParentNode, 7);

    //저번주 과제
    printf("Preorder : \n");
    printTreePreorder(pParentNode);

    printf("\nInorder : \n");
    printTreeInorder(pParentNode);

    printf("\nPostorder : \n");
    printTreePostorder(pParentNode);

    printf("\n");
    

    //이번주 과제(~9/13)
    printf("Search Data 3\n");
    if(searchTreeNode(pParentNode,3)!= NULL){
        printf("3 is existed\n\n");
    }
    else{
        printf("3 is not existed\n\n");
    }

    //Delete Data in Tree(pParentNode) -> 구현 후 아래 주석 내용된 코드 실행
    printf("Delete data 3\n");
    deleteTreeNode(&pParentNode, 3);
    printf("Delete data 2\n");
    deleteTreeNode(&pParentNode, 2);
    printf("Delete data 4\n");
    deleteTreeNode(&pParentNode, 4);

    //Search Data in Tree(pParentNode) -> 과제(~9/13)
    printf("\nSearch Data 4\n");
    if(searchTreeNode(pParentNode,4) != NULL){
        printf("4 is existed\n\n");
    }
    else{
        printf("4 is not existed\n\n");
    }

    //Pinrt Data in Tree(pParentNode)
    printf("Preorder : \n");
    printTreePreorder(pParentNode);

    printf("\nInorder : \n");
    printTreeInorder(pParentNode);

    printf("\nPostorder : \n");
    printTreePostorder(pParentNode);

    printf("\n\n");

    //Copy Tree(pParentNode) into Tree(cParentNode) -> 과제(~9/13)
    copyTreeNode(pParentNode, &cParentNode);

    //Print Data in Tree(cParentNode) -> 과제(~9/13)
    printf("Preorder\t: ");
    printTreePreorder(cParentNode);
    printf("\nInorder\t: ");
    printTreeInorder(cParentNode);
    printf("\nPostorder\t: ");
    printTreePostorder(cParentNode);
    printf("\n\n");

    //Compare Data between two Trees -> 과제(~9/13)
    if(compareTwoTree(pParentNode, cParentNode))
        printf("Two trees are equal\n");
    else
        printf("Two trees are different\n");

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
    if(bt == NULL)
        return;
    printTreeInorder(bt->left);
    printf("%3d", bt->data);
    printTreeInorder(bt->right);
}

void printTreePostorder(Node* bt){
    //Left->Right->Visit(Root)
    //Hint : 재귀함수 사용

    if(bt == NULL)
        return;
    printTreePostorder(bt->left);
    printTreePostorder(bt->right);
    printf("%3d",bt->data);
}

void printTreePreorder(Node* bt){
    //Visit(Root)->Left->Right
    //Hint : 재귀함수 사용

    if(bt == NULL)
        return;
    printf("%3d",bt->data);
    printTreePreorder(bt->left);
    printTreePreorder(bt->right);
}

Node* searchTreeNode(Node* bt, int value){
    while (bt != NULL && bt->data != value) {
        //현재 p 노드의 데이터와 같지 않을 경우
        //BST의 원리에 맞게 탐색
        //현재 가리키고 있는 노드의 값이 찾을려고 하는 값보다 작은 경우
        if (bt->data < value) {
            bt = bt->right;
        } else if (bt->data > value) {
            bt = bt->left;
        }
    }
    //찾았으면 해당 노드의 주소를 반환
    //못찾았으면 NULL을 반환함
    return bt;
}

Node* searchTreeParentNode(Node* bt, int value){
    //bt 노드 직전 노드인 부모 노드 변수
    Node* parentNode = NULL;
    //bt 노드의 데이터가 value와 같을 때까지 탐색
    while(bt != NULL && bt->data != value){
        //부모 노드가 bt 노드를 가리키고
        //bt노드는 다음 자식 노드로 이동
        parentNode = bt;
        if(bt->data < value){
            bt = bt->right;
        }
        else if(bt->data > value){
            bt = bt->left;
        }
    }
    return parentNode;
}

void deleteTreeNode(Node** bt, int value){
    Node* parentNode = NULL; //지울 노드의 부모 노드
    Node* delNode = NULL; // value 값을 갖고 있는 지울 노드
    Node* childNode = NULL; //지울 노드의 자식 노드
    Node* succNode = NULL; // Degree 2 노드를 지울 때 필요한 successor 노드

    parentNode = searchTreeParentNode(*bt, value);
    delNode = searchTreeNode(*bt, value);
    if(delNode == NULL){
        printf("There is no %d\n",value);
        return;
    }
    //Case 1. 자식 노드가 하나도 없는 경우
    if((delNode->left == NULL) && (delNode-> right == NULL)){
        //지울 노드가 root 노드인 경우
        if(parentNode == NULL){
            (*bt) = NULL;
        }
        else{
            //지울 노드가 부모 노드의 어느 쪽에 있는지 확인하고 NULL로 지정
            if(parentNode->left == delNode){
                parentNode->left = NULL;
            }
            else{
                parentNode->right = NULL;
            }
        }
    }
    //Case 2. 자식 노드가 하나 존재할 때
    else if((delNode->left == NULL) || (delNode->right == NULL)){
        //지울 노드의 자식 노드를 childNode 변수를 이용해 가리키도록 함
        childNode = (delNode->left != NULL)? delNode->left : delNode-> right;

        //지울 노드가 root 노드인 경우
        if(parentNode == NULL){
            (*bt) = childNode;
        }
        else{
            //지울 노드가 부모 노드의 어느 쪽에 있는지 확인하고 자식 노드를 연결
            if(parentNode->left == delNode){
                parentNode->left = childNode;
            }
            else{
                parentNode->right = childNode;
            }
        }
    }
    //과제(~9/13)
    //Case 3. 자식 노드가 둘 다 있는 경우 -> ppt 참고
    //Successor 노드 : 지울 노드의 right child node의 가장 left child node
    if((delNode->left != NULL) && (delNode-> right != NULL)){
        childNode = delNode->right;
        while(childNode->left->left != NULL){
            childNode = childNode->left;
        }
        succNode = childNode->left;
        childNode->left = NULL;
        if(parentNode == NULL){
            delNode->data = succNode->data;
            free(succNode);
            return;
        }
        else if(parentNode->left == delNode){
            parentNode->left = succNode;
        }
        else{
            parentNode->right = succNode;
        }
        succNode->left = delNode->left;
        succNode->right = delNode->right;
    }

    //Case 1~2의 delNode dealloc 해줌
    free(delNode);
}

//과제(~9/13)
void copyTreeNode(Node* src, Node** dst){
    Node * curNode = NULL, * copyNode = NULL;
    Node * curParentNode = NULL, * copyParentNode = NULL;
    if(src == NULL){
        printf("copy error: src should be exist\n");
    }
    if(*dst != NULL){
        printf("copy error: dst should be NULL\n");
    }
    curNode = src;
    insertTreeNode(dst, curNode->data);
    copyNode = *dst;
    while(curNode != NULL){
        curParentNode = searchTreeParentNode(src, curNode->data);
        copyParentNode = searchTreeParentNode(*dst, copyNode->data);

        if(curNode->left != NULL && copyNode->left == NULL){
            curNode = curNode->left;
            insertTreeNode(dst, curNode->data);
            copyNode = copyNode->left;
        }
        else if (curNode->right != NULL && copyNode->right == NULL){
            curNode = curNode->right;
            insertTreeNode(dst, curNode->data);
            copyNode = copyNode->right;
        }
        else{
            curNode = curParentNode;
            copyNode = copyParentNode;
        }
    }
}

//과제(~9/13)
int compareTwoTree(Node* t1, Node* t2){
    if(t1 == NULL && t2 == NULL){
        return TRUE;
    }
    else if(t1 == NULL || t2 == NULL){
        return FALSE;
    }
    return (t1->data == t2->data && compareTwoTree(t1->left, t2->left) && compareTwoTree(t1->right, t2->right));
}