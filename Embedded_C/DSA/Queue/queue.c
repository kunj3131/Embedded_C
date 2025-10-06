#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull(){
    return(front == (((rear+1)%SIZE)));
}

int isEmpty(){
    return front == -1;
}

void inqueue(int value){
    if(isFull()){
        printf("Full\n");
        return;
    }
    if(isEmpty())
        front = 0;
    
    rear = (rear+1)%SIZE;
    queue[rear] = value;
    printf("value is inserted %d \n",queue[rear]);
}

void dequeue(){
    if(isEmpty()){
        printf("isEmpty\n");
        return;
    }
    printf("Deleted queue %d\n", queue[front]);
    if(front == rear){
        // front = rear = -1;
    }
    else{
        front = (front+1)%SIZE;
    }
}

void display(){
    if(isEmpty()){
        printf("Empty\n");
        return;
    }
    printf("queue: ");
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear)
            break;
        i = (i+1)%SIZE;
    }
    printf("\n");
}

int main(){
    inqueue(10);
    inqueue(10);
    inqueue(10);
    inqueue(10);
    inqueue(10);
    dequeue();
    display();
    inqueue(20);
    display();
}