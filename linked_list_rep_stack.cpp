#include <iostream>
#include <stack>
#include <stdlib.h>
#define capacity 6
using namespace std;

class node
{
	public:
		int data;
		node* next;
};
node* top;
int count=0;
void push(int data)
{
	node* temp = new node();
	if(count>capacity){
	  cout<<"Overflow"<<endl;
	  exit(1);
	}
  temp -> data = data;
  temp -> next = top;
  top = temp;
  count++;  
}

int peek()
{
	if(top==NULL)
		exit(1);
	else
		return top->data;
}

void pop()
{
	node* temp;
	if(top==NULL){
	  cout<<"Stack empty"<<endl;
	}
	else
	{
	  temp = top;
	  top = top->next;
	  temp->next = NULL;
	  free(temp);
	  count--;
	}
}
void display()
{
	node* temp;
	if(top==NULL){
		cout<<"stack empty"<<endl;
	}
	else
	{
		temp = top;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	 cout<<endl;
	}
}
int main(int argc,const char* argv[])
{
	for(int i=1;i<argc;i++)
	{
		push(atoi(argv[i]));
	}
	
	display();
	cout<<count<<endl;
	cout<<"Top element is "<<peek()<<endl;
	pop();
	pop();
	cout<<count<<endl;
	cout<<"Top element is "<<peek()<<endl;
	return 0;
}
