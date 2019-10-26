//head value is globally declared and can be accessed anywhere
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
void insert(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}
void Print()
{
    struct Node* temp=head;
    printf("List is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(void)
{
printf("Enter the number of elements:\n");
int n,x;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    scanf("%d",&x);
    insert(x);
    Print();
}
}
