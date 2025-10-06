#include <stdio.h>

int main(){
	
	char name[20];
	fputs("Enter your name ",stdout);
        fgets(name,sizeof(name),stdin);
        fputs(name,stdout);

	char b;
        printf("Enter a character\n");
        putchar(b);
        b=getchar();
        printf("Enterd Character is %c\n",b);

	int a;
	printf("Enter value of a ");
	scanf("%d",&a);
	printf("You have enterd %d\n",a);

	char string[50];
	int x,y;
	sprintf(string,"value of a=%d and b=%c",a,b);
	printf("%s\n",string);
	sscanf(string,"a=%d and b=%d",&y,&x);
	printf("value of x=%d and y=%d\n",x,y);

	



// Upcoming line code is for clear an input buffer
	// while (getchar() != '\n' && getchar() != EOF);

// Witout clearing buffer it not takes any input reason is in ReadMe file	
//	char name[20];
//	fputs("Enter your name",stdout);
//	fgets(name,sizeof(name),stdin);
//	fputs(name,stdout);

	return 0;
}
