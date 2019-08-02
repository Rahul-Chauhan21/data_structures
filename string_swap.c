//swap two strings
#include <stdio.h>

#include<stdlib.h>

void swap_string(char str[],int);

int main()

{

    char str[20];

    gets(str);

    int x=strlen(str);

    x-=1;

    swap_string(str,x);

    return 0;

}

void swap_string(char str[],int x)

{

    char str1[20];

    int i=0,j=0;

            while(str[i]!=' '){

                    str1[i]=str[i];

                    i++;

                            }

    i+=1;

            while(str[i]!=NULL){

                        str[j]=str[i];

                        i++;j++;

                            }

    i=0;

    str[j]=' ';

    j+=1;

            while(j<=x){

                    str[j]=str1[i];

                    i++;j++;

                    }

    puts(str);

}
