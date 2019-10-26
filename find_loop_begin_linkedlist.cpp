#include<iostream>
#include "node.cpp"

using namespace std;
void find_loop_begin(Node* head)
{
    if(head==NULL||head->next==NULL){
        cout<<"No loop"<<endl;
        return;
    }
    Node* slow = head, * fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast&&fast->next)
    {
        if(slow==fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow!=fast)
    {
        cout<<"No loop found"<<endl;
        return;
    }
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    cout<<"Start of the loop is: "<<slow->data<<endl;
}
void insert_before(Node** head,int val)
{
    Node* temp = new Node();
    temp -> data = val;
    temp -> next = *head;
    *head = temp;
}
void printList(Node * head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
}
int main(void)
{
    Node* head = NULL;
    cout<<"Total Nodes:"<<endl;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert_before(&head,x);
    }
    head->next->next->next->next->next=head->next->next;//take total nodes greater or equal to 5.
    find_loop_begin(head);
    return 0;
}
