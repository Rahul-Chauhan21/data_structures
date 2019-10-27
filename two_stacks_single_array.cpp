#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

class mystacks
{
 int *arr;
 int size;
 int top1,top2;
	public:
 		mystacks(int n)
		{
		 size = n;
		 arr = new int[n];
		 top1 = -1;
		 top2 = size;
		}
		
	void push1(int x)
	{
		if(top1<top2-1)
		{
			top1++;
			arr[top1]=x;
		}
		else
		{
			cout<<"stack 1 is full"<<endl;
			exit(1);
		}
	}
	void push2(int x)
	{
		if(top1< top2-1)
		{
			top2--;
			arr[top2] = x;
		}
		else
		{
			cout<<"stack 2 is full"<<endl;
			exit(1);
		}
	}
	int pop1()
	{
		if(top1>=0)
		{
			int x = arr[top1];
			top1--;
			return x;
		}
		else
		{
			return -1;
		}
	}
	int pop2()
	{
		if(top2<size)
		{
			int x = arr[top2];
			top2++;
			return x;
		}
		else
		{
			return -1;
		}
	}	

};

int main(int argc,const char* argv[])
{
	int n = atoi(argv[1]);
	mystacks ts(n);
	int i =2;
	while(n--){
		ts.push1(atoi(argv[i++]));
	
		ts.push2(atoi(argv[i++]));
		n = n-2;
	}
	 
    return 0; 
}
