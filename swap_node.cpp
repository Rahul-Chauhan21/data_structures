#include <iostream>
#include "node.cpp"

using namespace std;
class mylinked_list
{
    Node* head;
public:
    mylinked_list()
    {
        this->head=NULL;
    }
    void insert_after(int val)
    {
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
    void swap_node(int x,int y)
    {
        if(x==y)
            return;
        Node* prevX = NULL;
        Node* currX = head;
        while(currX!=NULL&&currX->data!=x){
            prevX = currX;
            currX = currX->next;
        }
        Node* prevY = NULL;
        Node* currY = NULL;
        currY = head;
        while(currY!=NULL&&currY->data!=y){
            prevY = currY;
            currY = currY->next;
        }
        if (currX == NULL || currY == NULL)
            return;
        if(prevX!=NULL)
            prevX->next = currY;
        else
            head = currY;
        if(prevY!=NULL)
            prevY->next = currX;
        else
            head = currX;
        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
    void display()
    {
        while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
        cout<<endl;
    }
};
int main(void)
{
    mylinked_list* l1 = new mylinked_list();
    int x,y,val,n;
    cout<<"No of nodes:"<<endl;
    cin>>n;
        for(int i=0;i<n;i++){
            cin>>val;
            l1->insert_after(val);
        }
        //l1->display();
        cout<<"input two keys to be swapped"<<endl;
        cin>>x>>y;
        l1->swap_node(x,y);
        l1->display();
    return 0;
}
