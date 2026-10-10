/**
 * Check and Count Number of ones in given num
 */

#include <stdio.h>

int func(int num){
	int count=0;
	while(num){
		count+=(num&1);
		num>>=1;
	}
	return count;
}

int main(){
	printf("%d\n",func(11));
	return 0;
}
