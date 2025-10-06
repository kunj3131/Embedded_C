#include <stdio.h>
#include <stdlib.h>

typedef struct st{
    int value;
    struct st* next;
} ST;

void add(ST **head){
    ST* new;
    new = malloc(sizeof(ST));
    printf("Enter value: ");
    scanf("%d", &new->value);
    new->next = *head;
    *head = new;
}

ST* Traversal(ST *head){
    while(head!=NULL){
        printf("%d , %p\n", head->value, head->next);
        head = head->next;
    }
    return head;
}

void main(){
    ST *head = NULL;
    char ch;
    for(int i=0;i<=3;i++){
        // printf("Enter ch: ");
        // scanf(" %c", &ch);
        // if(ch == 'y' || ch =='Y'){
            add(&head);
        // }
        // else{
            // Traversal(head);
            // break;
        // }
    }
    Traversal(head);
}
