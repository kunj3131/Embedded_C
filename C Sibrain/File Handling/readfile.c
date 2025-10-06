#include <stdio.h>
int main(){
	FILE *ptr = fopen("file.txt","r");
	char data[50];
	while(fgets(data,sizeof(data),ptr)!=NULL)
		printf("%s\n",data);
	fclose(ptr);
	return 0;
}
