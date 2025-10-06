#include <stdio.h>

#define alpha 100 //Macro which is also const

void constant(){
	const int a =5;
	int b=4;
	// Read only variable error
	// a=b;
	// Increment on read only variable error
	// a++; 
	printf("%d\n",a);
	printf("%d\n",a+1);  // We can perform operation using that varible but we can't perform operation on variable
	printf("%d\n",a>>1); // We can Perform Operations using that variable but we can't perform operation on variable
}


void pointerToConstant(int *x, int *y){
	const int *a=x;
	printf("%d\n",*a);
	a=y;
	printf("%d\n",*a);
	// Error to readonly variable
	// *a=10;
	printf("%d\n",*a);
}

void constantPointerToVariable(int *x, int *y){
	int *const a=x;
	printf("%d\n",*a);
	// Error to readonly variable
	// a=y;
	*a=10;
	printf("%d\n",*a);
}

void constantPointerToConstantVariable(int *x, int *y){
	const int *const a=x;
	printf("%d\n",*a);
	// Error to readonly variable
	// a=y;
	// Error to Readonly variable
	// *a=10;	
       	// printf("%d\n",*a);
	
}

//Constant using enum function

enum value{
	beta=43
};


int main(){
	int a=5, b=2;


//	constant();
//	pointerToConstant(&a,&b);	
//	constantPointerToVariable(&a, &b);	
	constantPointerToConstantVariable(&a, &b);
	
	printf("%d\n",alpha);
	// if we have change the value of macro in main
	#ifdef alpha
	#undef alpha
	#define alpha 23
	#endif 
	printf("%d\n",alpha);

	printf("%d\n",beta);
	return 0;
}
