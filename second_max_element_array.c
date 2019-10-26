//Second Max element by finding max sum pair
#include <stdio.h>
#include <stdlib.h>

void second_max(int arr[],int n)
{
    int max_element=arr[n-1];
    int second_max=arr[0];
    int curr_max=second_max+max_element;
        for(int i=0;i<n-1;i++)
        {
            if(curr_max<arr[i]+max_element)
            {
                curr_max=arr[i]+max_element;
                second_max=arr[i];
            }
            if(second_max>max_element)
            {
                int temp=second_max;
                second_max=max_element;
                max_element=temp;
            }
        }
    printf("Max element is: %d\n",max_element);
    printf("Second max element is: %d\n",second_max);
    printf("Max sum is: %d\n",curr_max);
}
int main(void)
{
    int n;
    printf("Input the number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    second_max(arr,n);
    return 0;
}
