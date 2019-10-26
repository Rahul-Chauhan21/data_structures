#include<iostream>
#include<cstdlib>
using namespace std;
void stable_selectionsort(int arr[],int n)
{
int min_index;
    for(int i=0;i<n-1;i++) //n-1 since last element has to be sorted.
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min_index]>arr[j])
                min_index=j;
        }
        int key=arr[min_index]; //temp replace in the end of rotation
        while(min_index>i)
        {
            arr[min_index]=arr[min_index-1]; //rotation to the right till min_index reduces till i
            min_index--;
        }
        arr[i]=key;// smallest element on correct position.
    }
}
int main(int argc,const char* argv[])
{
    //cline inputs
    int n=argc-1,j=0;
    int arr[n];
        for(int i=0;i<argc;i++)
        {
            if(i==0)continue;
            arr[j++]=atoi(argv[i]);
        }

    stable_selectionsort(arr,n);

        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    return 0;
}
