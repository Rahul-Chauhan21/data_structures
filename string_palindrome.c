#include <stdio.h>

#include<stdlib.h>

void string_palindrome(char str1[],int);

int main()

{

    char str1[20];

    scanf("%s",str1);

    int x=strlen(str1);

    string_palindrome(str1,x);

    return 0;

}

void string_palindrome(char str1[],int x){

    char str2[x];

    int i=0,count=0;

    x-=1;

                     while(x>=0){

                            str2[i]=str1[x];

                            x--;i++;

                            }

    i=0;

                    while(str1[i]!=NULL){

                                if(str1[i]==str2[i])

                                    count++;

                                i++;

                                    }

                             if(count==strlen(str1))

                                 printf("string is a palindrome");

                             else

                                 printf("string is not a palindrome");

}
