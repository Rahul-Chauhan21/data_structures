#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next[2];
};
int count = 0;
struct node* new_node(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next[0] = temp->next[1] = NULL;
    return temp;
}

void inorder(struct node *root, int arr[],int *j)
{
    if (root == NULL)
        return;
    inorder(root->next[0], arr,j);
    arr[++*j] = root->data;
    inorder(root->next[1], arr,j);
}
void MinHeap(struct node *root, int arr[], int *i)
{
    if (root == NULL)
        return;
    root->data = arr[++*i];
    MinHeap(root->next[0], arr, i);
    MinHeap(root->next[1], arr, i);
}

void convertToMinHeap(struct node *root,int n)
{
    int arr[n];
    int i = -1;
    int j = -1;
    inorder(root, arr,&j);
    MinHeap(root, arr, &i);
}

struct node* insert(struct node* root,int val){
    if(root == NULL)
        root = new_node(val);
    else if(val<=root->data){
        root->next[0] = insert(root->next[0],val);
    }
    else{
        root->next[1] = insert(root->next[1],val);
    }
    return root;
}
void max_toys(struct node* root,int *k){
    if(root == NULL||k<=0)
        return;
    *k = *k-(root->data);
    if(*k>0){
        count++;
    }
    max_toys(root->next[0],k);
    max_toys(root->next[1],k);
}
int main(int argc,const char* argv[]){
    struct node* root = NULL;
    int k,n;
    printf("Enter amt:\n");
    scanf("%d",&k);
    printf("Total no nodes:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
    }
    convertToMinHeap(root,n);
    /*int k = atoi(argv[1]);
    root = insert(root,atoi(argv[2]));
        for(int i=3;i<argc;i++){
            root = insert(root,atoi(argv[i]));
        }
    convertToMinHeap(root,argc-2);*/
    max_toys(root,&k);
    printf("%d",count);
    return 0;
}
