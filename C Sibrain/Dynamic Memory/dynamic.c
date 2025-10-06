#include <stdio.h>
#include <stdlib.h>

int dynamic(){
	return malloc(0);
}

void Malloc(){
	int *ptr = (int *)malloc(sizeof(int)*5);
	for(int i=0;i<5;i++){
		ptr[i]=i+1;
		printf("%d\n",ptr[i]);
	}
	free(ptr);
	for(int i=0;i<5;i++){
		printf("%d\n",ptr[i]);
	}
}

void Calloc(){
	int *ptr = (int *)calloc(5,sizeof(int));
	for(int i=0;i<5;i++){
		ptr[i]=i+1;
		printf("%d\n",ptr[i]);
	}
	free(ptr);
	for(int i=0;i<5;i++){
		printf("%d\n",ptr[i]);
	}
}

int main(){
	printf("%d\n",dynamic());  // Positive no.:allocate memory, if it fails return NULL

	Malloc();
	Calloc();
	return 0;
}
