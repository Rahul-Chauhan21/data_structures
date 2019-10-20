#include<iostream>
#include<stack>
#include<stdlib.h>
#define MIN_LEN 5
using namespace std;
/// 1 2 3 4 5
// O: 1 3 5
void print_digits(int arr[],int n){
    if(n==0)
        exit(1);
    int count = 1;
    stack<int> st;
        for(int i=0;i<n;i++){
            st.push(arr[i]);
            if(count&1){
                cout<<st.top();
                st.pop();
            }
            count++;
        }
}
int main(void){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    print_digits(arr,n);
    return 0;
}
