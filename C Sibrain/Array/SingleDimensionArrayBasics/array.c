/*
 *
 *
 * This File contains a basic understanding of Array and Single dimention Array
 *  -Traversal
 *  -Reverse
 *  -Sum
 *  -Find Maximum number
 *  -Find the total elements
 *
 *
 */

#include <stdio.h>

long unsigned int accessArrayElement(long unsigned int pos,long unsigned int a[]){
	return a[pos];
}

/*
 *
 
 In C we can't crete a function of Array creation
 due to we havr to pass an argument of an array
 and when we pass the array as an arguments it's pass as a pointer.
 and we take a sizeof(pointer) which is always 8.
 
 *
 *
long unsigned int array_size(long unsigned int a[]){
	int size = sizeof(a);
	int div = sizeof(a[0]);
	int len = size/div;
	printf("%d %d %d\n",size,div,len);
	return len;
}
*
*
*/

void ReverseArray(long unsigned int length, long unsigned int *a){
	printf("Reverse Array: ");
	for(int i=length-1;i>=0;i--){
		printf("%lu ",a[i]);
	}
	printf("\n");
}

void arrayTraversal(long unsigned int length,long unsigned int *a){
//	long unsigned int length = array_size(a);
	printf("Array List: ");
	for(int i=0;i<length;i++){
		printf("%lu ",a[i]);
	}
	printf("\n");
}

long unsigned int sumOfArray(long unsigned int length,long unsigned int *a){
	long unsigned int sum=0;
	for(int i=0;i<length;i++){
		sum+=a[i];
	}
	return sum;
}

long unsigned int MaxFromArray(long unsigned int length, long unsigned int *a){
	long unsigned int max=a[0];
	for(int i=1;i<length;i++){
		if(max<=a[i]){
			max=a[i];
		}
	}
	return max;
}

long unsigned int AddElementAtFirst(long unsigned int length, long unsigned int *a){
	for(int i=length-1;i>=0;i--){
		a[i]=a[i-1];
	}
	a[0]=10;
	return *a;
}

long unsigned int AddElementAtLast(long unsigned int length, long unsigned int *a){
	a[length-1]=11;
	return *a;
}

long unsigned int AddElementAtPos(long unsigned int length, long unsigned int *a, long unsigned int pos){
	for(int i=length-1;i>=pos;i--){
		a[i]=a[i-1];
	}	
	a[pos]=12;
}

int main(){
	long unsigned int a[8]={1,2,3,4,5};
	
	long unsigned int pos = 2;
//	long unsigned int length=5;
	long unsigned int length = sizeof(a)/sizeof(a[0]);	
	printf("Length: %lu\n",length);
//	array_size(a);
//	printf("%lu\n",array_size(a));
	

	arrayTraversal(length, a);
//	accessArrayElement(pos,a);
	
	ReverseArray(length,a);

	printf("Array Element at pos: %lu\n",accessArrayElement(pos,a));
	printf("Sum: %lu\n",sumOfArray(length,a));
	printf("max: %lu\n",MaxFromArray(length,a));
	AddElementAtFirst(length,a);
	arrayTraversal(length,a);
	AddElementAtPos(length,a,pos);
	arrayTraversal(length,a);
	AddElementAtLast(length,a);
	arrayTraversal(length,a);
	return 0;
}



