/* The question says design a mark sheet that implies no mark alloted to a question is same and the sum of the total marks is minimum. for example
a sequence of marking scheme is provided below and you need to alter it such that total marks for the question paper is minimum.
*/
// 2 2 2 2 2 4 // sequence of marks is always sorted.
// 2 3 4 5 6 7 // since 2 was already there we updated it to 3 and so and so forth.
// for the next question of 2 marks we cannot change it to 3 since it is already used, so its updated to 4.
// 27  output..
#include<iostream>
#include<stack>
using namespace std;

int main(void){
    long long n,sum=0;
    cin>>n;
    long long arr[n];
    stack<long long> st;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        if(!st.empty()&&arr[i]<=st.top()){
            sum+=st.top()+1;
            st.push(st.top()+1);
        }
        else
        {
            st.push(arr[i]);
            sum+=arr[i];
        }
    }
    cout<<sum;
    return 0;
}
