#include <iostream>
#include <stack>
using namespace std;
#define N 8
//celebrity is 1
bool matrix[N][N] = {{0, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 0}};
bool knows(int a,int b)
{
    return matrix[a][b];
}
int find_celebrity(int n){
    /*int C= 0;
    for(int i = 1; i < n; i++){
        if(knows(C,i)){
            C = i;
        }
    }*/
    stack<int>s;
    int C;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();
    while(s.size()>1){
        if(knows(A,B))
        {
            A = s.top();
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }
        C = s.top();
        s.pop();
        if(knows(C,B))
            C = B;
        if(knows(C,A))
            C = A;
            cout<<C<<endl;
        for(int i=0;i<n;i++){
            if(i!=C &&(knows(C,i)||!knows(i,C)))
                return -1;
        }
        return C;
}
int main(void){
    int n = 4;
    int id = find_celebrity(n);
    id==-1 ? cout<<"No celebrity" : cout<<"Celebrity id: "<<id;
    return 0;
}
