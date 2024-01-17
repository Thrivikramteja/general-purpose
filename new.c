#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void insertion_sort(int arr[],int n);



void insertion_sort(int arr[],int n)
{
   for(int j=0;j<n;j++)
   {
    int key=arr[j];
    int i=j-1;
    while(i>=0 && arr[i]>key)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=key;
   }

   for(int i=0;i<n;i++)
   {
    printf("%d ",arr[i]);
   }

}
   




    