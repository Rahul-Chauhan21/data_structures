#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void string_reverse(char str[]);
int main()
{
	char str[50];
	scanf("%s",str);
	string_reverse(str);
	return 0;
}
void string_reverse(char str[]){
	int i=0;
	char temp;
	int x=strlen(str)-1;
	while(str[i]!=NULL){
		if(i<x){
		temp=str[i];
		str[i]=str[x];
		str[x]=temp;
		}
		i++;x--;
	}
	printf("reversed string is %s ",str);
}
