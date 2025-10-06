/*
 *
 *
 *Function Pointer
 *
 *
 */


#include <stdio.h>

struct ST{
	int wid, len;
	int (*rect)(struct ST*, int wid, int len);
	float (*circ)(struct ST*, int redius);
};

int rectangle(struct ST* st,int length, int width){
	st->wid=width;
	st->len=length;
	int size = st->wid * st->len;
	return size;
}

float circle(struct ST* st, int redius){
	st->len = redius;
	float size = st->len * st->len *3.14;
	return size;
}

void cons(struct ST *st){
	st->wid=0;
	st->len=0;
	st->rect = rectangle;
	st->circ = circle;
}

int rec(int length, int width){
	return length*width;
}

int squa(int length,int width){
	return length*width;
}

int calculation(int length, int width, int (*fun)(int, int)){
	return fun(length, width);
}

int main(){
	struct ST st;	
	cons(&st);
	printf("%f\n",st.circ(&st, 5));
	printf("%d\n",st.rect(&st, 4,10));

	int (*area[])(int, int) = {rec,squa};
	printf("%d\n",area[0](5,10));
	printf("%d\n",area[0](5,1));

	printf("%d\n",calculation(3,10,rec));
	printf("%d\n",calculation(2,10,squa));
	return 0;
}


