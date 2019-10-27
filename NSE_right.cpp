#include <iostream>
#include <stack>
using namespace std;
void printNSE(int arr[],int n){
	int ans[n];
	for(int i=0;i<n;i++){
		ans[i]=-1;
	}
	stack<int> s;
		for(int i=0;i<n;i++){
			while(!s.empty()&&arr[s.top()]>arr[i]){
				int a = s.top();
				s.pop();
				ans[a]=arr[i];
			}
			s.push(i);
		}
	for(int i = 0;i<n;i++)
		cout<<ans[i]<<" ";
}
int main(int argc,const char* argv[]){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printNSE(arr,n);
  return 0;
}
