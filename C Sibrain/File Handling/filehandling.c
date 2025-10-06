#include <stdio.h>

int main(){
	FILE *ptr = fopen("file.txt","r");
	if (ptr ==NULL){
		printf("File is not openend\n");
		ptr = fopen("file.txt","w");
		if(ptr == NULL)
			printf("file is not created");	
	}

	char data[50] = "Hello world You are on planet";
	ptr = fopen("file.txt","w");
	fputs(data,ptr);
	fclose(ptr);
	return 0;
}
