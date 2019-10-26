#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int key;
    Node* next[2];
    Node(){};
    Node(int data)
    {
        this->key = data;
        next[0]=NULL;
        next[1]=NULL;
    }
};
void printLevelOrder(Node *root)
{
    if (root == NULL) return;
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int nodeCount = q.size();
            while(nodeCount>0){
            Node *node = q.front();
            cout << node->key << " ";
            q.pop();
            if (node->next[0] != NULL)
                q.push(node->next[0]);
            if (node->next[1] != NULL)
                q.push(node->next[1]);
                nodeCount--;
            }
            cout<<endl;
    }
}


void insert(Node* root,int key){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(!temp->next[0]){
            temp->next[0] = new Node(key);
            }
            else
                q.push(temp->next[0]);
            if(!temp->next[1]){
            temp->next[1] = new Node(key);
            break;
            }
            else
                q.push(temp->next[1]);
    }
}
int main(void){
    Node* root = new Node(1);
    root->next[0] = new Node(2);
    root->next[1] = new Node(3);
    root->next[0]->next[0] = new Node(4);
    root->next[0]->next[0] = new Node(5);
    cout<<"BFS traversal before insertion: "<<endl;
    printLevelOrder(root);
    int key = 6;
    insert(root,key);
    cout<<endl;
    cout<<"BFS traversal after insertion: "<<endl;
    printLevelOrder(root);
    return 0;
}


