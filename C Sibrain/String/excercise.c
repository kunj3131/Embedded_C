/*
 *
 *
 *
 *This file contains a c programming excercise of String
 *
 *
 *
 */


#include <stdio.h>

// Reversing a string

void reverse(char *str, int length){
	for(int i=length-1;i>=0;i--){
		printf("%c",str[i]);
	}
	printf("\n");
}

void pallindrom(char *str, int length){
	int count=0;
	for(int i=0;i<length/2;i++){
		if(str[i]==str[length-i-2]){
			printf("pallindrome\n");
		}
		else{
			printf("Not\n");
		}
	}
}

char* countingChar(char *str, int length){
	for(int i=0;i<length-1;i++){
	int count=0;
		for(int j=0;j<length;j++){
			if(str[i]==str[j]){
				count++;
			}
		}
		printf("%c is repeating %d times\n",str[i],count);
	}
	return str;
}

int stringCompare(char *str1, char *str2, int length){
	int flag=0;
	for(int i=0;i<length;i++){
		if(str1[i]==str2[i]){
			flag=0;
		}
		else{
			flag=1;
		}
	}
	if(flag==0){
		printf("Both String are same %d\n",flag);
		return flag;
	}
	else{
		printf("Both string are not same %d\n",flag);
		return flag;
	}
}

char* ConcatenateString(char *str1, char *str2){
	int i=0, j=0;
	while(str1[i]!='\0'){
		i++;
	}
	while(str2[j]!='\0'){
		str1[i]=str2[j];
		i++;
		j++;
	}
	str1[i]='\0';
	return str1;
}


void findingSubstring(char *str1, char *str2) {
	int count=0;
	while(str2[count]!='\0'){
		count++;
	}
	int flag=0,j=0;
	for(int i=0;str1[i]!='\0';i++){
		if(j!=count){
			if(str1[i]==str2[j]){
				flag++;
				j++;
				printf("%c",str1[i]);
			}
			else{
				flag=0;
				j=0;
			}
		}
	}
	printf("\n");
}

char* removingDuplicate(char *str){
	int j=0,count=0;
	while(str[count]!='\0'){
		count++;
	}
	for(int i=1;i<count;i++){
		if(str[i]!=str[j]){
			j++;
			str[j]=str[i];
		}
	}
	return str;
}

int main(){
	char string[]={"Hello World"};
	int length = sizeof(string)/sizeof(string[0]);
	//reverse(string,length);
	//char string1[]="rld";
	//char str[]={"civic"};
	//char stri[]={"civic"};
//	int len = sizeof(str)/sizeof(str[0]);
//	printf("%d\n",len);
//	pallindrom(str,len);
//	countingChar(str,len);
//	stringCompare(stri,str,len);
//	printf("%s\n",ConcatenateString(str, string));
//	findingSubstring(string, string1);
	printf("%s\n",removingDuplicate(string));
	return 0;
}
