#include <iostream>
#include <stack>
using namespace std;
bool check_pair(char open,char close){
    if(open=='('&&close==')')return true;
    else if(open=='{'&&close=='}')return true;
    else if(open=='['&&close==']')return true;
    return false;
}
bool check_balance_para(string s){
    int n = s.length();
    stack<char> set;
    for(int i = 0;i < n;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            set.push(s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(set.empty()||!check_pair(set.top(),s[i]))
                return false;
            else
                set.pop();
        }
    }
    return set.empty()?true:false;
}

int main(void){
    cout<<"Enter the expression"<<endl;
    string s;
    cin>>s;
    if(check_balance_para(s))
        cout<<"balanced"<<endl;
    else
        cout<<"not balanced\n";
    return 0;
}
