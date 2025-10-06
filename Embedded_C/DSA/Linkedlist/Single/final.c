#include <stdio.h>
#include <stdlib.h>

typedef struct ST{
    int value;
    struct ST *next;
}ST;

ST *createNode(int value){
    ST *newNode = malloc(sizeof(ST));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void traversal(ST *head){
    ST *current = head;
    while(current!=NULL){
        printf("%d ", current->value);
        current = current->next;
    }
}

ST* insertAtBeginning(ST* head, int value) {
    ST* newNode = malloc(sizeof(ST));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = head;
    return newNode;  // new head
}


int main(){
    ST *head = NULL, *temp;
    int i, data, n=10;
    for(i=0;i<n;i++){
        data = i;
        printf("for node i: %d value is %d \n", i, data);
        ST *newNode = createNode(data);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
        head = insertAtBeginning(head, data);
        // head = insertInBetweeen(head, 3);
    }
    traversal(head);
    ST *current = head;
    ST *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}