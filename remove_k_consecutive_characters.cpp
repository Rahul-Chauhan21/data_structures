#include <iostream>
#include <stack>

using namespace std;
void remove_consec(string X,int freq){
    int n = X.length();
    stack<char> st;
        int c=1;
        st.push(X[0]);
        for(int i = 1; i <=n; i++){
            if(X[i]==st.top()){
                c++;
                st.push(X[i]);
            }
            else{
                if(c<freq){
                    c = 1;
                    st.push(X[i]);
                }
                else
                {
                    char ch = st.top();
                    while(!st.empty()&&st.top()==ch){
                        st.pop();
                    }
                    c = 1;
                    st.push(X[i]);
                }
            }
        }
        string res = "";
        int m = st.size();
        for(int i = 0;i < m; i++){
            res = st.top() + res;
            st.pop();
        }
        cout<<res;
}
int main(void){
    string X;
    cin>>X;
    remove_consec(X,3);
    return 0;
}
