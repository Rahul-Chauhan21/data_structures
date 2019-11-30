//height of a binary tree and level order using height of the binary tree and queue

#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500
struct node{
    int data;
    struct node* next[2];
};
// function prototypes
struct node** createQueue(int*,int*); // create a pointer to pointer of type node to store about 500 nodes
void enQueue(struct node**,int*,struct node*);
struct node* deQueue(struct node**,int*);
void printGivenLevel(struct node*,int);
int max(int a,int b){
    return (a > b) ? a : b;
}
struct node* new_node(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next[0] = temp->next[1] = NULL;
    return temp;
}
int height_binary_tree(struct node* root){// to understand more precisely create a table of call stack with cols as caller, no of lines(as per code// use raw code), left_height and right_height
    if(root==NULL)
        return 0;
        /*                                                                                          6       height of 6 is max of (height of left subtree (2) and height of right subtree (1) )+1
        int leftHeight = height_binary_tree(root->next[0]);                                     5       4
        int rightHeight = height_binary_tree(root->next[1]);                                7
        */
    return max(height_binary_tree(root->next[0]),height_binary_tree(root->next[1]))+1;
}
struct node* construct(int arr[],int i,struct node* root,int n){
    if(i<n){
        struct node* temp = new_node(arr[i]); // memory assigned on each call after all the memories get assigned a child is connected to parent by returning that connection to the caller in the call stack
        root = temp;
            if((arr[2*i+1]!=-1)&&(2*i+1<n))
                root->next[0] = construct(arr,2*i+1,root->next[0],n);

            if((arr[2*i+2]!=-1)&&(2*i+2<n))
                root->next[1] = construct(arr,2*i+2,root->next[1],n);
    }
    return root;
}
void printLevelOrderUsingHeight(struct node* root,int h){
    int i;
    for(i=1;i<=h;i++){
        printGivenLevel(root,i);
    }
}
void printGivenLevel(struct node* root,int level){
    if(root==NULL)
        return;
    if(level==1)
        printf("%d ",root->data);
    else if(level>1){
        printGivenLevel(root->next[0],level-1);
        printGivenLevel(root->next[1],level-1);
    }
}
void printLevelOrderUsingQueue(struct node* root){
    int rear,front;
    struct node **queue = createQueue(&front,&rear);
    struct node *temp = root;

    while(temp){
        printf("%d ",temp->data);
        //enqueue left child
            if(temp->next[0])
                enQueue(queue,&rear,temp->next[0]);
            if(temp->next[1])
                enQueue(queue,&rear,temp->next[1]);
        temp = deQueue(queue,&front); //dequeuing the queue is simply moving the front pointer one step ahead
    }
}
struct node** createQueue(int *front,int *rear){
    struct node **queue = (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}
void enQueue(struct node **queue,int *rear, struct node *new_Node){
    queue[*rear] = new_Node;
    (*rear)++;
}
struct node *deQueue(struct node **queue,int *front){
    (*front)++;
    return queue[*front-1];
}
int main(void){
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    struct node* root = NULL;
    root = construct(arr,0,root,n);
    int h = height_binary_tree(root);
    printf("Height of binary tree is: %d\n",h);
    printf("Level order of the binary tree using height function is:\n");
    printLevelOrderUsingHeight(root,h);
    printf("\nLevel order of the binary tree using a custom queue is:\n");
    printLevelOrderUsingQueue(root);
    return 0;
}
