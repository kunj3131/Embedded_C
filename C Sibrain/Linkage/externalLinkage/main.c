#include <stdio.h>

extern int externalLinkage;

int main(){
	printf("%d\n",externalLinkage);
	return 0;
}
