#include <stdio.h>
#include <stdlib.h>

typedef struct ST{
    int value;
    struct ST * next;
}ST;

ST *linkedListTraversal(ST *ptr){
    while(ptr!=NULL){
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
    return ptr;
}

ST *deleteAtFirst(ST * head){
    ST * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

ST *deleteInBetween(ST *head, int index){
    ST *p = head;
    ST *q = head->next;
    int i = 0;
    while(i != (index-1)){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

ST *deleteAtEnd(ST *head){
    ST *p = head;
    ST *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

ST *deleteAtIndex(ST *head, int data){
    ST *p = head;
    ST *q = head->next;
    while(q->value != data && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->value == data){
        p->next = q->next;
        free(q);
    }
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
    third->next = NULL;

    linkedListTraversal(head);

    // head = deleteAtIndex(head, 8);
    // linkedListTraversal(head);

    // head = deleteAtEnd(head);
    // linkedListTraversal(head);

    head = deleteInBetween(head, 2);
    linkedListTraversal(head);

    // head = deleteAtFirst(head);
    // linkedListTraversal(head);
    
    return 0;
}