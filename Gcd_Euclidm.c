#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(int argc,const char* argv[])
{
 int n=argc-1,j=0;
 int arr[n];

    for(int i=0;i<n;i++)
    {
        if(i==0)continue;
        arr[j++]=atoi(argv[i]);
    }
    int result=arr[0];

    for(int i=1;i<n;i++)
    {
        result=gcd(arr[i],result);
    }
return 0;
}
