#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next[2];
};
void printGivenLevel(struct node* root,int level);
int height(struct node* node);
struct node* new_node(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next[0] = temp->next[1] = NULL;
    return temp;
}
int curr_max = 1, max = 0;
int res;
struct node* p= NULL;

void inorder(struct node* root)
{

    if (root == NULL) {
        return;
    }

    inorder(root->next[0]);

    if (p!= NULL) {

        if (root->data == p->data) {
            curr_max++;
        }

        else {
            curr_max = 1;
        }
    }

    if (curr_max > max) {
        max = curr_max;
        res = root->data;
    }

    p = root;
    inorder(root->next[1]);
}

int find(struct node* root)
{
    inorder(root);
    return res;
}
/*void inorder(struct node* root){
    if(root==NULL)
    return;
    inorder(root->next[0]);
    printf("%d",root->data);
    inorder(root->next[1]);
}*/
struct node* insert(int arr[],struct node* root,int i,int n)
{
	if(i<n){
		struct node* temp = new_node(arr[i]);
		root = temp;

		if(arr[(2*i+1)]!=-1&&(2*i+1)<n)
			root->next[0] = insert(arr,root->next[0],2*i+1,n);
		if(arr[(2*i+2)]!=-1&&(2*i+1)<n)
			root->next[1] = insert(arr,root->next[1],2*i+2,n);
	}
	return root;
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->next[0], level-1);
        printGivenLevel(root->next[1], level-1);
    }
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->next[0]);
        int rheight = height(node->next[1]);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}
int main(int argc,const char* argv[]){
    int n;
    scanf("%d",&n);
    int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    struct node* root = insert(arr,root,0,n);
    //inorder(root);
    printLevelOrder(root);
    printf("%d",find(root));
    return 0;
}
