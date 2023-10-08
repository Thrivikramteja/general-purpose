#include<stdio.h>

int main(){

    int num,isprime=1;

    for(num=2;num<=100;num++){
        isprime=1;
        for(int i=2;i<num;i++){
            if(num%i==0){
                isprime=0;
                break;
            }
        }if(isprime){
            printf("%d\n",num);
        }
    }
    
return 0;

}