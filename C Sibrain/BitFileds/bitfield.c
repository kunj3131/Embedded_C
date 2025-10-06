/*
 *
 *
 *
 * Bit Field
 *
 *
 *
 */

#include <stdio.h>

struct info{
	int srNo:3;
	int conatactno:20;
	char gend;
};



int main(){
	printf("%lu\n",sizeof(struct info));
	struct info personal = {1,3845,'M'};
	printf("%d, %d, %c\n",personal.srNo, personal.conatactno, personal.gend);	
	return 0;
}
