#include<iostream>
#define ROTATIONS 2
#define M 4
#define N 4
using namespace std;
void rotate(int row,int col,int arr[M][N],int n1,int m1){
	int curr=0,prev=0;
	if(row>M||col>N)
		return;
	if(row+1==M|col+1==N)
		return;
	prev=arr[row+1][col];
	for(int i=col;i<n1;i++){
		curr=arr[row][i];
		arr[row][i]=prev;
		prev=curr;
	}
	for(int i=row+1;i<n1;i++){
		curr=arr[i][n1-1];
		arr[i][n1-1]=prev;
		prev=curr;
	}
	for(int i=n1-2;i>=col;i--){
		curr=arr[n1-1][i];
		arr[n1-1][i]=prev;
		prev=curr;
	}
	for(int i=n1-2;i>=row+1;i--){
		curr=arr[i][col];
		arr[i][col]=prev;
		prev=curr;
	}
	row++;
	col++;
	n1--;
	m1--;
	rotate(row,col,arr,n1,m1);
}

int main(void){
	int arr[M][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int n1=N;
	int m1=M;
	for(int i=0;i<ROTATIONS;i++)
		rotate(0,0,arr,n1,m1);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}s
	return 0;
}
