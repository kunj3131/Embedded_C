#include <stdio.h>
#include <stdlib.h>

typedef struct ST{
    int value;
    struct ST *next;
}ST;

void linkedlistTraversal(ST *ptr){
    while(ptr){
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}

ST *insertAtFirst(ST *head){
    ST* ptr;
    ptr = malloc(sizeof(ST));
    printf("Enter value: ");
    scanf("%d", &ptr->value);
    ptr->next = head;
    head = ptr;
    return head;
}

ST *insertInBetweeen(ST *head, int index){
    ST* ptr;
    ST* p = head;
    ptr = malloc(sizeof(ST));
    int i = 0;
    while(i != (index-1)){
        p = p->next;
        i++;
    }
    printf("Enter value: ");
    scanf("%d", &ptr->value);
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

ST *insertAtEnd(ST *head){
    ST *ptr;
    ptr = malloc(sizeof(ST));
    ST *p = head;
    while(p->next !=NULL){
        p = p->next;
    }
    printf("Enter value: ");
    scanf("%d", &ptr->value);
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

ST *insertAfterNode(ST *prevNode){
    ST *ptr;
    ptr = malloc(sizeof(ST));

    printf("Enter value: ");
    scanf("%d", &ptr->value);
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    // return head;
}

int main(){
    ST * head;
    ST * first;
    ST * second;     
    ST * third;

    head = malloc(sizeof(ST));
    first = malloc(sizeof(ST));
    second = malloc(sizeof(ST));
    third = malloc(sizeof(ST));

    head->value = 7;
    head->next = first;

    first->value = 8;
    first->next = second;

    second->value = 9;
    second->next = third;

    third->value = 10;
    third->next = NULL;
    
    linkedlistTraversal(head);

    head = insertAtFirst(head);
    linkedlistTraversal(head);

    // head = insertInBetweeen(head, 3);
    // linkedlistTraversal(head); 

    head = insertAtEnd(head);
    linkedlistTraversal(head); 

    // insertAfterNode(head);
    // linkedlistTraversal(head);

    free(head);
    return 0;
}