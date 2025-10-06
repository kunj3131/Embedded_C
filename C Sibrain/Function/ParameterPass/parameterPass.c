#include <stdio.h>

// call by value

struct st{
	int a1,b1;
};

struct st func1(int x, int y){
	struct st stru;
	stru.a1=y;
	stru.b1=x;
	return stru;
}	

void value(int x, int y){
	int z=0;
	z=x;
	x=y;
	y=z;
	printf("Value (in fun): first %d second %d\n",x,y);
}

void parameter(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(){
	int a=4,b=6;

	struct st st = func1(a,b);
	printf("structure : first %d second %d\n",st.a1,st.b1);

	value(a,b);
	printf("Value (after func) : first %d second %d\n",a,b);

	parameter(&a,&b);
	printf("Parameter : first %d second %d\n",a,b);

	return 0;
}
