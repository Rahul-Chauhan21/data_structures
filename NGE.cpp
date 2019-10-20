#include <iostream>
#include <stack>

using namespace std;

void printNGE(int arr[], int n){
    int ans[n];
    for(int i=0;i<n;i++)
        ans[i]=-1;
    stack<int> mystack;
    for(int i =0;i<n;i++)
    {
        while(!mystack.empty()&&arr[i]>arr[mystack.top()]){
            int a = mystack.top();
            mystack.pop();
            ans[a] = arr[i];
        }
        mystack.push(i);
    }
    for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(void){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    printNGE(arr,n);
    return 0;
}
