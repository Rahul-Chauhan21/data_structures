#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;
class Node{
	public:
		int key;
		Node* next[2];
	Node(){};
	Node(int data){
		key = data;
		next[0]=NULL;
		next[1]=NULL;
	}
};

Node* construct_binary_tree(int arr[],Node* root,int i,int n)
{
	if(i<n){
		Node* temp = new Node(arr[i]);
		root = temp;

		if(arr[(2*i+1)]!=-1)
			root->next[0] = construct_binary_tree(arr,root->next[0],2*i+1,n);
		if(arr[(2*i+2)]!=-1)
			root->next[1] = construct_binary_tree(arr,root->next[1],2*i+2,n);
	}
	return root;
}

void printLevelOrder(Node* root_ref)
{
	if(root_ref==NULL) return;
	queue<Node *> q;
	q.push(root_ref);
	while(q.empty()==false)
	{
		Node *node = q.front();
		cout<<node->key <<" ";
		q.pop();
		
		if(node->next[0]!=NULL)
		q.push(node->next[0]);
		if(node->next[1]!=NULL)
		q.push(node->next[1]);
	}
}
int main(int argc,const char* argv[]){
    int n = argc-1;
	int arr[n];
	int j=0;
	for(int i=0;i<argc;i++)
	{
		if(i==0)continue;
		arr[j++]=atoi(argv[i]);	
	} 
	Node* root = construct_binary_tree(arr,root,0,n);  
    	printLevelOrder(root);   
    return 0; 
}
