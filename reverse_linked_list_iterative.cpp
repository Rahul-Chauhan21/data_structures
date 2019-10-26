#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
class linked_list
{
    Node* head;
public:
    linked_list();
    void traverse();
    void reverse_linked_list();
    void insert_linked_list(int val);
};
linked_list::linked_list()
{
    this->head = NULL;
}
void linked_list::insert_linked_list(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node* p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
void linked_list::reverse_linked_list()
{
    Node* p=NULL;
    Node* curr=NULL;
    Node* prev=NULL;
    p=head;
    curr=head;
    while(curr!=NULL)
    {
        p=p->next;
        curr->next=prev;
        prev=curr;
        curr=p;
    }
        head=prev;
}
void linked_list::traverse()
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    linked_list* list1 = new linked_list();
    int val,n;
    cout<<"Input the number of elements"<<endl;
    cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            list1->insert_linked_list(val);
        }
        list1->reverse_linked_list();
        list1->traverse();
    return 0;
}

