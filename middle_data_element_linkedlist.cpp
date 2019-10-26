#include <iostream>
#include "node.cpp"
using namespace std;
void insert_before(Node** head, int val)
{
    Node* temp= new Node();
    temp->data = val;
    temp -> next = *head;
    *head = temp;
}
void middle_element(Node* head)
{
    int count1=0;
    struct Node* mid = head;
        while(head!=NULL)
        {
            if(count1&1)
            {
                mid=mid->next;
            }
            ++count1;
        head=head->next;
        }
    if(mid!=NULL)
    {
        cout<<"Middle element is:"<<mid->data;
    }
}
int main(void)
{
    Node* head = NULL;
    int n;
    cout<<"Total Node:" <<endl;
    cin>>n;
    int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            insert_before(&head,x);
        }
    middle_element(head);
    return 0;
}
