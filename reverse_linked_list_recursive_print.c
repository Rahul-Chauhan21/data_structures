#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void reverse_linked_list(struct Node* head) //head is the pointer to the pointer to node
{
    if(head==NULL)
        return;
    reverse_linked_list(head->next);
    printf("%d-->",head->data);
}
void insert(struct Node** head,int val)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL)
        *head=temp;
    else
    {
        struct Node*p=*head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
int main(void){
    struct Node* head=NULL;
    int n;
    printf("Number of inputs\n");
    scanf("%d",&n);
    int val;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            insert(&head,val);
        }
    reverse_linked_list(head);
    return 0;
}
