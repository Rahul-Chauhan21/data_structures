
// C++ implementation of simple algorithm to find
// smaller element on left side
#include <iostream>
#include <stack>
using namespace std;

// Prints smaller elements on left side of every element
void printPrevSmaller(int arr[], int n)
{
  	int ans[n];
  	for(int i=0;i<n;i++)
      ans[i]=-1;
	stack<int> s;
  	for(int i=0;i<n;i++){
    	while(!s.empty()&&arr[s.top()]>=arr[i])
        {
          	s.pop();
        }
        if(!s.empty())
      	ans[i]=arr[s.top()];
      	s.push(i);
    }
  for(int i=0;i<n;i++)
  {
  	cout<<ans[i]<<" ";
  }
}

/* Driver program to test insertion sort */
int main()
{
	int arr[] = {39,27,11,4,24,32,32,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}
