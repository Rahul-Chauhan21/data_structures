#include <iostream>
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* next[2];
    Node(int data) 
    { 
        this->data = data;
	next[0]=NULL;
	next[1]=NULL;  
    } 
}; 

int height_binary_tree(Node* node)
{
	if(node==NULL)
	return 0;
	return max(height_binary_tree(node->next[0]),height_binary_tree(node->next[1]))+1;
}
  
int main(void) 
{ 
    struct Node *root = new Node(1); 
    root->next[0] = new Node(2); 
    root->next[1] = new Node(3); 
    root->next[0]->next[0]  = new Node(4); 
    root->next[0]->next[1] = new Node(5);
    root->next[0]->next[0]->next[1] = new Node(6);
    root->next[0]->next[0]->next[1]->next[1] = new Node(7);   
    cout<<"Height is:"<<height_binary_tree(root);   
    return 0; 
} 
