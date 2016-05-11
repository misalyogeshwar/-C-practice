#include <stdio.h>
#include <stdlib.h>


void print_sorted(int arr[],int start,int end)
{
    if(start > end)
        return;
    else
    {
        print_sorted(arr,start*2+1,end);
        printf("\t %d",arr[start]);
        print_sorted(arr,start*2 +2,end);
    }
}
int main()
{
    printf("Hello world!\n");
    int arr[] = {4,2,5,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_sorted(arr,0,size-1);
    return 0;
}
