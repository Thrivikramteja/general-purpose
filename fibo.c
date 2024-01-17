#include <stdio.h>

int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);

}

int main(int argc,char *argv)
{
    int n=5;
    printf("%d",fibo(n));


    return 0;
}