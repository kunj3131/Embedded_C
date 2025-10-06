#include <stdio.h>
#include "externalInternal.c"

extern int externalAndInternal;

int main(){
	printf("%d\n",externalAndInternal);
}
