//Time Complexity: O(n) Aux space: O(1)
#include <iostream>
using namespace std;
void max_diff(int arr[],int n)
{
    int m_diff=arr[1]-arr[0];
    int min_ele=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]-min_ele>m_diff)
            {
                m_diff=arr[i]-min_ele;
            }
            if(arr[i]<min_ele)
            {
                min_ele=arr[i];
            }
        }
     cout<<"Max difference is: "<<m_diff<<endl;
}
int main(void)
{
    int n;
    cout<<"Input number of elements"<<endl;
    cin>>n;
    int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    max_diff(arr,n);
return 0;
}
