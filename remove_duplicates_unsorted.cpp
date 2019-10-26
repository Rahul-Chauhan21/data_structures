#include <iostream>
#include <unordered_set>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
void append_to_list(struct Node** head,int key){
    struct Node* temp = new Node(); // 1 2
    temp->data = key;
    temp->next = NULL;
    if(*head==NULL){
        *head = temp;
    }
    else
    {
        struct Node* p = *head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = temp;
    }

}
void remove_duplicates_unsorted(struct Node* head){
    unordered_set<int> st;
    struct Node* curr = head;
    struct Node* prev = NULL;
    while(curr!=NULL){
        if(st.find(curr->data)!=st.end()){
            prev->next = curr->next;
            delete(curr);
        }
        else
        {
            st.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}
void print_list(Node* ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main(void){
    struct Node* head=NULL;
    int x,n;
    cout<<"Enter the no of nodes"<<endl;
    cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            append_to_list(&head,x);
        }
    print_list(head);
    remove_duplicates_unsorted(head);
    print_list(head);
    return 0;
}

