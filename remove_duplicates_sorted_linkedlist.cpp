#include <iostream>
using namespace std;

/* Link list node */
class Node
{
    public:
    int data;
    Node* next;
};

/* The function removes duplicates from a sorted list */
void removeDuplicates(Node* head)
{
    Node* curr = head;
    Node* next_next;
    if(curr==NULL)
        return;
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            next_next=curr->next->next;
            free(curr->next);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
}
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    /* Let us create a sorted linked list to test the functions
    Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    cout<<"Linked list before duplicate removal ";
    printList(head);

    /* Remove duplicates from linked list */
    removeDuplicates(head);

    cout<<"\nLinked list after duplicate removal ";
    printList(head);

    return 0;
}
