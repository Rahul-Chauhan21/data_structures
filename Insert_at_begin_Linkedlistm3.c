//Passing head by reference
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
 void insert(struct Node** pointerToHead,int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=*pointerToHead;
    *pointerToHead=temp;
}
void Print(struct Node* curr_head)
{

    printf("List is: ");
    while(curr_head!=NULL)
    {
        printf("%d ",curr_head->data);
        curr_head=curr_head->next;
    }
    printf("\n");
}
int main(void)
{
 struct Node* head=NULL;
 printf("Enter the number of elements:\n");
 int n,x;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        insert(&head,x);//head is a pointer to node
        Print(head);
    }
}

