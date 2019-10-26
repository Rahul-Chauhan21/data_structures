#include <iostream>
#include "node.cpp"

    using namespace std;

    class my_linkedlist
    {
        Node* head;
    public:
        my_linkedlist()
        {
            this->head=NULL;
        }
        void traverse();
        Node* insert_after(int val);
        void reverse_linkedlist(Node* p);
    };

    Node* my_linkedlist::insert_after(int val)
    {
        Node* p= new Node();
        p->data=val;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            Node* q=head;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
        }
        return head;
    }
    void my_linkedlist::reverse_linkedlist(Node* p)
    {
        if(p->next==NULL)
        {
            this->head = p;
            return;
        }
        reverse_linkedlist(p->next);
        Node* q= p->next;
        q->next = p;
        p->next = NULL;
    }
    void my_linkedlist::traverse()
    {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }

    int main(void)
    {
        my_linkedlist* lis = new my_linkedlist();
        int val,n;
        Node* head=NULL;
        cout<<"Input the number of elements"<<endl;
        cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>val;
                head=lis->insert_after(val);
            }
            lis->reverse_linkedlist(head);
            lis->traverse();
        return 0;
    }
