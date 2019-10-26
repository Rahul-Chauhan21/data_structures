#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void append_linkedlist(struct Node** pointertoHead,int x)
{
 struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
 temp->data=x;
 temp->next=NULL;
 if(*pointertoHead==NULL)
 {
  *pointertoHead=temp;
 }
 else
 {
     struct Node* p;
     p=*pointertoHead;
     while(p->next!=NULL) //having p!=null condition fails at the second index is input because the memory p->next will update to null thereby not linking the list.
     {
         p=p->next;
     }
     p->next=temp;
 }
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
 printf("Enter the number of values:\n");
 int n;
 scanf("%d",&n);
 int x;
    for(int i=0;i<n;i++)
         {
         scanf("%d",&x);
         append_linkedlist(&head,x);
         Print(head);
         }

 return 0;
}
