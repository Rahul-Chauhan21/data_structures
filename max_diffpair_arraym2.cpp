#include <iostream>
using namespace std;

void max_difference(int arr[],int n)
{
    int diff=arr[1]-arr[0];
    int max_ending_here=diff;
    int max_so_far=max_ending_here;
        for(int i=1;i<n-1;i++)
        {
            diff=arr[i+1]-arr[i];
            if(max_ending_here+diff>0)
                max_ending_here+=diff;
            else{
                max_ending_here=diff;
            }
            if(max_so_far<max_ending_here)
            {
                max_so_far=max_ending_here;
            }
        }
        cout<<"Max difference is: "<<max_so_far<<endl;
}
int main(void)
{
    int n;
    cout<<"Input the number of elements: "<<endl;
    cin>>n;
    int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    max_difference(arr,n);
return 0;
}
