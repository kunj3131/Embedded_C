#include <stdio.h>

extern void hello();

int main(){
	printf("Calling function from .so file\n");
	hello();
	return 0;
}
