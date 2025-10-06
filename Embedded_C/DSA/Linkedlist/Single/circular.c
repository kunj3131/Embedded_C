#include <stdio.h>
#include <stdlib.h>

typedef struct ST{
    int value;
    struct ST * next;
}ST;

void linkedListTraversal(ST *head){
    ST *ptr = head;
    do{
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }while(ptr!=head);
}

ST *insertAtFirst(ST *head){
    ST *ptr;
    ptr = malloc(sizeof(ST));
    printf("Enter value");
    scanf("%d", &ptr->value);
    ST *p = head->next;
    while(p->next != head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;
}

int main(){
    ST *head;
    ST *first;
    ST *second;
    ST *third;

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
    third->next = head;

    linkedListTraversal(head);

    head = insertAtFirst(head);
    linkedListTraversal(head);
}