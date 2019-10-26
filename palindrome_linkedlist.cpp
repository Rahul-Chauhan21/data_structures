#include<iostream>
#include <stack>
#include "node.cpp"
using namespace std;

int isPalin(Node** head)
{
    Node* temp;
    stack <int> s;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL)
    {
        int i=s.top();
        s.pop();
        if(*head->data!=i){
            return 0;}
        *head=*head->next;
    }
    return 1;
}
void append_after(Node** head,int ndata)
{
    Node* temp = new Node();
    temp->data=ndata;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
        {
            Node* p=*head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            cout<<"inserted"<<endl;
            p->next=temp;
        }
}
int main(void)
{
    Node* head=NULL;
    int x,n;
    cout<<"Total nodes: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        append_after(&head,x);
    }
    int result=isPalin(&head);
    cout<<result;
    if(result==1)
        cout<<"Palindrome";
    else
        cout<<"Not";
        return 0;
}

