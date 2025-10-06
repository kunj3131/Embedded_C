#include <stdio.h>

int main(){
	int var = 1;
	int *ptr = &var;

	printf("%d\n",*ptr);

	*ptr = *ptr+1;
	printf("%d\n",*ptr);

	//This increments a ptr address not in value if we have to perform operations on ptr only option ptr+1
//	*ptr++;
//	printf("%d\n",*ptr);     //output is updated adress

	int var1=1;
	int *ptr1 = &var1;
	printf("%d\n",*ptr1);

	if(*ptr1>*ptr)
		printf("%d %d hello\n",*ptr1,*ptr);
	else
		printf("%d %d world\n",*ptr,*ptr1);

	if(ptr1>ptr)
		printf("%p %p hello\n",ptr1,ptr);
	else
		printf("%p %p world\n",ptr,ptr1);

	
}
