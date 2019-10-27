#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
	public:
		int key;
		Node* next[2];
		Node(){};
		Node(int key){
			this->key = key;
			next[0]=NULL;
			next[1]=NULL;
		}
};
int search(int in[],int start,int end,int key)
{
	for(int i=start;i<=end;i++)
	{
		if(in[i]==key)
			return i;
	}
}
Node* construct_tree(int pre[],int in[],int start,int end){
	static int pindex=0;
	if(start>end)
		return NULL;
	Node* node = new Node(pre[pindex++]);
	if(start==end)
		return node;
	int iindex = search(in,start,end,node->key);
	node->next[0]= construct_tree(pre,in,start,iindex-1);
	node->next[1]= construct_tree(pre,in,iindex+1,end);
}
void inorder(Node* node)
{
	if(node==NULL)
		return;
	inorder(node->next[0]);
	cout<<node->key<<" ";
	inorder(node->next[1]);

}
int main(int argc,const char*argv[]){
	int n1=atoi(argv[1]);
	int n2=atoi(argv[2]);
	int in[n1];
	int pre[n2];
	int i,j=3;
	for(int i=0;i<n1;i++)
	{
		in[i]=atoi(argv[j++]);
	}
	for(int i=0;i<n2;i++)
	{
		pre[i]=atoi(argv[j++]);
	}
	/*int pre[]={1,2,4,5,3,7};
	int in[]={4,2,5,1,3,7};*/
	Node* root = construct_tree(pre,in,0,5);
	inorder(root);
  return 0;
}
