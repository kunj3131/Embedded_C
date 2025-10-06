#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
    int roll_no;
    char name[10];
    float marks;
    struct data *next;
} ST;

void add_begin(ST **ptr) {
    ST *new;
    new = malloc(sizeof(ST));
    printf("Enter roll no\n");
    scanf("%d", &new->roll_no);
    printf("%p\n", new->roll_no);
    printf("Enter Name\n");
    scanf("%s", new->name);
    printf("%p\n", new->name);
    printf("Enter marks\n");
    scanf("%f", &new->marks);
    printf("%p\n", new->marks);
    new->next = *ptr;
    printf("%p\n", new->next);  //null
    *ptr = new;
    printf("%p\n", ptr);        //0x7ffc04311a90
}

void print(ST *p) {
    while (p) {
        printf("%d, %s, %f, %p\n", p->roll_no, p->name, p->marks, p->next);
        p = p->next;
    }
}

int main() {
    ST *hptr = NULL;
    char op;
    do {
        add_begin(&hptr);
        printf("Do you want another node (Y/N)? ");
        scanf(" %c", &op); // Added space before %c to consume any leftover newline character
    } while (op == 'Y' || op == 'y');
    print(hptr);
    return 0;
}


/*

#include <stdio.h>
#include <stdlib.h>

typedef struct ST{
    int value;
    struct ST *next;
}ST;

ST *create(int value){
    ST *newNode = malloc(sizeof(ST));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

ST *begin(ST *head, int value){
    ST *newNode = malloc(sizeof(ST));
    newNode->value = value;
    newNode->next = head;
}

ST *between(ST *head, int index){
    ST *p;
    ST *ptr = head;
    p=malloc(sizeof(ST));
    int i=0;
    while(i!=(index-1)){
        ptr = ptr->next;
        i++;
    }
    printf("Enter");
    scanf("%d", &p->value);
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

int traversal(ST *head){
    while(head){
        printf("%d ",head->value);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int i;
    ST *head=NULL, *temp=NULL;
    for(i=0;i<10;i++){
        // head = begin(head, i);
        ST* new = create(i);
        printf("%d ", i);
        if(head==NULL){
            head = new;
            temp = new;
        }
        else{
            temp->next = new;
            temp = new;
        }
    }
    head = between(head, 5);
    printf("\n");
    traversal(head);
    ST *current = head;
    ST *nextNode;
    while(current!=NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

*/