#include <iostream>
#include "node.cpp"
using namespace std;

int count_freq(Node* head, int val)
{
    static int count1=0;
    if(head==NULL)
        return count1;
     if(head->data==val)
            count1++;
     count_freq(head->next,val);
}
void insert_before(Node** head,int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->next =*head;
    *head = temp;
}
int main(void)
{
    Node* head = NULL;
    int n;
    cout<<"Total nodes: "<<endl;
    cin>>n;
    int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            insert_before(&head,x);
        }
    int count=count_freq(head,3);
    cout<<count;
    return 0;
}
