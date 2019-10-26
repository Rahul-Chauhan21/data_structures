//Passing copy of head as current_head
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
 struct Node* insert(struct Node* curr_head,int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=curr_head;
    curr_head=temp;
    return temp;
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
        head=insert(head,x);
        Print(head);
    }
}

