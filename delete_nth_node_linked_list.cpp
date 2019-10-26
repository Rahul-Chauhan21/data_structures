#include <iostream>
#include "node.cpp"

using namespace std;

class my_linked_list
{
private:
    Node* head;
public:
    my_linked_list(){
    this->head=NULL;
    }
    void delete_nth_node(int val)
    {
        if(head==NULL)
            return;
        if(val==0)
        {
            head=head->next;
            return;
        }
        Node* p=this->head;
        for(int i=0;i<val-1;i++)
        {
            p=p->next;
        }
        if(p==NULL||p->next==NULL)
            return;
        /*Node* p1=p;
        p1=p1->next;
        p->next=p1->next;*/
        p->next=p->next->next;
    }
    void insert_after(int x)
    {
        Node* temp= new Node();
        temp->data=x;
        temp->next=NULL;
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
    void display()
    {
        while(head!=NULL)
        {
            cout<<head->data;
            head=head->next;
        }
    }
};

int main(void)
{
    int n,x,val;
    cout<<"Input the number of element:"<<endl;
    cin>>n;
    my_linked_list* list1=new my_linked_list();
        for(int i=0;i<n;i++)
        {
            cin>>x;
            list1->insert_after(x);
        }
    cout<<"Input the nth node to be deleted"<<endl;
    cin>>val;
        list1->delete_nth_node(val);
        list1->display();
    return 0;
}
