#include<iostream>
#include "node.cpp"
using namespace std;

void printNthFromLast(Node* head,int n)
{
    static int i=0;
    if(head==NULL)
        return;
    printNthFromLast(head->next,n);
    i++;
    if(i==n)
        cout<<head->data;
}
void insert_linkedlist(Node** head,int val)
{
    Node* temp = new Node();
    temp->data=val;
    temp->next=*head;
    *head=temp;
}
int main(void)
{
    Node* head = NULL;
    int input,x;
    cout<<"Input the number of elements: "<<endl;
    cin>>input;
        for(int i=0;i<input;i++)
        {
            cin>>x;
            insert_linkedlist(&head,x);
        }
        printNthFromLast(head,3);
    return 0;
}
