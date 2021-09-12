#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    struct QueueNode* next;
    int data;
}QueueNode;

typedef struct Queue{
    int capacity;
    int curCount;
    QueueNode* rear;
    QueueNode* front;
}Queue;

void Enqueue(Queue* queue, int data);
QueueNode* Dequeue(Queue* queue);
void show(Queue* queue);
void delete(Queue* queue);
void isNull(QueueNode* node);

int main(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->capacity = 5;
    queue->curCount = 0;
    
    //Enqueue Part
    Enqueue(queue, 10);
    Enqueue(queue, 20);
    Enqueue(queue, 30);
    Enqueue(queue, 40);
    Enqueue(queue, 50);
    Enqueue(queue, 60);
    show(queue);

    //Delete Part
    QueueNode* delNode = Dequeue(queue);
    delNode = Dequeue(queue);
    isNull(delNode);
    
    delNode = Dequeue(queue);
    isNull(delNode);
    show(queue);

    delNode = Dequeue(queue);
    isNull(delNode);
    show(queue);
    //Delete all of node in Queue
    delete(queue);
    show(queue);

    return 0;
}

//Dequeue한 Node를 삭제 하는 함수
void isNull(QueueNode* node){
    if(node == NULL){
        printf("Warning : Nothing to dequeue\n\n");
    }
    else{
        printf("Dequeued Node : %d\n\n", node->data);
        free(node);
    }
}
void Enqueue(Queue* queue, int data){
    //When queue is not exist
    if(queue == NULL){
        printf("Enqueue() error : queue is NULL\n");
        return;
    }

    //When queue is full -> error
    if(queue->curCount == queue->capacity){
        printf("Enqueue() error : queue is FULL\n");
        return;
    }

    QueueNode* tmpNode = NULL, *newNode = NULL;
    newNode = (QueueNode*)malloc(sizeof(QueueNode));

    //When memory is full
    if(newNode == NULL){
        printf("Enqueue() error : out of memory\n");
        return;
    }
    newNode->data = data;
    //Condition 1 -> Try to Enqueue when queue is empty : 과제
    if(queue->curCount == 0){
        queue->front = newNode;
        queue->rear = newNode;
        queue->curCount += 1;
    }
    //Condition 2 -> Try to Enqueue when queue is not empty : 과제
    else{
        tmpNode = queue->front;
        while(tmpNode != queue->rear){
            tmpNode = tmpNode->next;
        }
        tmpNode->next = newNode;
        queue->rear = newNode;
        queue->curCount += 1;
    }
}

QueueNode* Dequeue(Queue* queue){
    QueueNode * tmpNode = queue->front;
    QueueNode * returnNode = NULL;
    if(queue->curCount == 0){// empty 일 때
        printf("Dequeue error: queue is empty");
        return NULL;
    }
    returnNode = queue->front;
    queue->front = queue->front->next;
    returnNode->next = NULL;
    queue->curCount -= 1;
    return returnNode;
}

void show(Queue* queue){
    if(queue == NULL){
        printf("show() error\n");
        return;
    }
    if(queue->curCount == 0){
        printf("show() error : Queue is empty\n\n");
        return;
    }
    QueueNode* tmpNode = queue->front;
    printf("front->\t");
    while(tmpNode){
        printf("[%d]  ",tmpNode->data);
        tmpNode = tmpNode->next;
    }
    printf("<-rear\n");
    printf("=========================\n\n");
}

void delete(Queue* queue){
    //과제
    QueueNode *curNode = queue->front;
    while(curNode != NULL){
        QueueNode * deleteNode = curNode;
        curNode = curNode->next;
        isNull(deleteNode);
        queue->curCount -= 1;
    }

}

