#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{

    int data;
    struct Node *Next;

}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){

    int i;
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->Next=NULL;
    last=first;

    for(int i=1;i<n;i++){

        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->Next=NULL;
        last->Next=t;
        last=t;
    }
}

void create2(int A[],int n){

    int i;
    struct Node *t,*last;

    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->Next=NULL;
    last=second;

    for(int i=1;i<n;i++){

        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->Next=NULL;
        last->Next=t;
        last=t;
    }

}

int count(struct Node *p)
{
    int count=0;

    while(p!=NULL){
        count++;
        p=p->Next;
    }
    return count;
}

void Display_sum_of_elements_in_the_linked_list(struct Node *p)
{
    int sum=0;   
    while(p!=NULL){
        sum+=p->data;
        p=p->Next;
    }
    printf("%d",sum);
}

void Recursive_display(struct Node *p){

    if(p!=NULL){
        printf("%d ",p->data);
        Recursive_display(p->Next);
    }
}

void insert(int pos,int x,struct Node *p){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(pos<0 || pos > count(p)){
        return;
    }

    if(pos==0){
        t->Next=first;
        first=t;
    }else if(pos>0){
        p=first;
        for(int i=0;i<pos-1;i++){
            p=p->Next;
        }
        t->Next=p->Next;
        p->Next=t;
    }
}
 
void sorted_insert(struct Node *p,int x){

    struct Node *t,*q=NULL;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->Next=NULL;

}

void Remove_duplicates(struct Node *p)
{
    struct Node *q=first->Next;

    while(q!=NULL)
    {  
        if(p->data!=q->data)
        {
            p=q;
            q=q->Next;
        }
        else
        {
            p->Next=q->Next;
            free(q);
            q=p->Next;
        }
    }
}

void reversal1(struct Node *p)
{
    int i=0,*arr;
    arr=(int *)malloc(sizeof(int)*count(p));
    struct Node *q;

    while(p!=NULL)
    {
        arr[i]=p->data;
        p=p->Next;
        i++;
    }
    q=first;
    i--;
    while(q!=NULL)
    {
        q->data=arr[i];
        q=q->Next;
        i--;
    }
}

void reversal2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->Next;
        q->Next=r;
    }
    first=q;
}

void concat(struct Node *p,struct Node *q)
{
    third=p;
    while(p->Next!=NULL)
    {
        p=p->Next;
    }
    p->Next=q;
}

int main(){

    int A[]={1,2,3,4,5};
    int B[]={10,20,30,40,50};
    create(A,sizeof(A)/4);
    create2(B,sizeof(B)/4);
    
    Recursive_display(first);
    printf("\n");
    Recursive_display(second);
    printf("\n");
    concat(second,first);
    Recursive_display(third);


    return 0;
}