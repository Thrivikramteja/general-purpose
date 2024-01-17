#include <stdio.h>

int main()
{
    char *str;
    int n[7],l;
    scanf("%s",str);
    l=strlen(str);
    for(int i=0;i<l;i++)
    {
        if(str[i]=='I')
            n[i]=1;
        else if(str[i]=='V')
            n[i]=5;
        else if(str[i]=='X')
            n[i]=10;
        else if(str[i]=='L')
            n[i]=50;
        else if(str[i]=='C')
            n[i]=100;
        else if(str[i]=='D')
            n[i]=500;
        else if(str[i]=='M')
            n[i]=1000; 
    }

    int number;

    for(int i=0;i<l;i++)
    {
        

        
    }
    return 0;
}