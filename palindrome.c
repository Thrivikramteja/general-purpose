#include <stdio.h>

int palindrome(int n)
{
   int reversed_number=0;
   int remainder=0;
   int actual_number=n;

   while(actual_number!=0)
   {
    remainder=actual_number%10;
    reversed_number=reversed_number*10+remainder;
    actual_number=actual_number/10;
   
   }
   if(reversed_number==n){
    return 1;
   }else{
    return 0;
   }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    if(palindrome(n)){
        printf("%d is a palindrome\n",n);
    }else{
        printf("%d is not a palindrome",n);
    }

    return 0;
}