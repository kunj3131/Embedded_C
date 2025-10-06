#include <stdio.h>

int main(){
	int pointerVar=10;
	int *pointer = &pointerVar;
	printf("value of pointerVar %d\n",pointerVar);
	printf("value of pointerVar %d\n",*pointer);
	printf("address of pointerVar in decimal %d\n",pointer);
	printf("address of pointerVar in hex %p\n",pointer);
	printf("address of pointerVar in decimal %d\n",&pointerVar);
	printf("address of pointerVar in hex %p\n",&pointerVar);
	printf("address of pointer in decimal %d\n", &pointer);
	printf("address of pointer in hex %p\n",&pointer);
	printf("size of ponterVar %lu\n",sizeof(pointerVar));
	printf("size of pointer %lu\n",sizeof(pointer));

	int *ptr = NULL;
	printf("size of pointer %lu\n",sizeof(ptr));

	void *ptr1;
	printf("size of pointer %lu\n",sizeof(ptr1));

	
}
