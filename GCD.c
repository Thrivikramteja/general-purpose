#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *m,int *n)
{
    *m=*m+*n;
    *n=*m-*n;
    *m=*m-*n;
}

int gcd(int m,int n)
{
    if(m==n) return m;
    else
     if(m>n) return gcd(m-n,n);
     else return gcd(n,n-m);
}

int GCD(int m,int n)
{
    
   if(m%n==0)
    {
        return n;
    }else {
        return GCD(n,m%n);
    } 
}

void Array_print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int arr[5]={1,2,3,4,5};

    clock_t begin=clock();
    Array_print(arr,5);
    clock_t end=clock();
    double time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("%f",time);

}