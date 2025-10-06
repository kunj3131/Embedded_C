/*
 *
 *
 *This file contains a c Program of String basics and its function
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>

void array(char arr[3][11]){
	for(int i=0;i<3;i++){
		printf("%s\n",arr[i]);
	}
}

void pointer(char *arr[3]){
	for(int i=0;i<3;i++){
		printf("%s\n",arr[i]);
	}
}

int main(){
	char str[]={'h','e','l','l','o',' ','w','o','r','l','d'};
	printf("%s\n",str);
	
	char str1[]={"Hello World"};
	printf("%s\n",str1);

	char str2[]="Hello World";
	printf("%s\n",str2);

	str2[5]='L';
	printf("%s\n",str2);

	printf("string length: %lu\n",strlen(str2));
	long unsigned int length=sizeof(str)/sizeof(str[0]);
	printf("length: %lu\n",length);
	
	//String 2 copy into string 1
	printf("String Copy: %s\n",strcpy(str1,str2));
	
	char str3[10];
	//strncpy is for copy only n bytes string 1 copy into string 2
	printf("copy n bytes: %s\n",strncpy(str3,str1,3));
	
	memset(str2,'\0',sizeof(str2));
	printf("copy n bytes: %s\n",strncpy(str2,str1,3));
	
	//append string str1+str2
	printf("string append: %s\n",strcat(str1,str3));
	
	//append string using strncat to n bytes
	printf("String append n bytes: %s\n",strncat(str2,str1,4));

	memset(str2,'\0',sizeof(str2));
	memset(str3,'\0',sizeof(str3));

	strcpy(str2,"Hello");
	strcpy(str3,"Hello");
	
	//strcmp return 0: same, random value: not same
	printf("string compare: %d\n",strcmp(str2,str3));
	//strncmp
	printf("string compare n bytes: %d\n",strncmp(str2,str3,3));
	
	//strchr: first occurance of a given char in string
	printf("string compare with char : %s\n",strchr(str2,'l'));
	
	//strrchr: last occurance of a given char in string
	printf("string compare with char: %s\n",strrchr(str2,'l'));

	//strstr: first occurance of a given string in string
	//if string not found it returns 0 otherwise it return the rest of string
	printf("string compare with string: %s\n",strstr(str2,str3));

	//Split a string from provided character
	char *t = strtok(str2,"l");
	while(t!=NULL){
		printf("%s\n",t);
		t = strtok(NULL,"l");
	}

	char ar[3][11]={"Hello","world","Helloworld"};
	array(ar);
	char *arr[]={"Hello","World","Hello World"};
	pointer(arr);
	return 0;
}
