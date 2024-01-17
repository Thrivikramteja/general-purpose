#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;

    first = (struct Node *)malloc(sizeof(struct Node ));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node) );
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

int count(struct Node *p)
{
    int count=0;

    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int maximum(struct Node *p)
{
    int max=p->data;

    while(p!=NULL)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return 1;
        }
        p=p->next;
    }
    return 0;
}

void insert(struct Node *p,int x,int index)
{
    if(index<0||index>count(p))
    {
        return;
    }
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
           p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void insert_last(int x)
{
    struct Node *p,*t,*last;
    p=first;
    t=(struct Node *)malloc(sizeof(struct Node ));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
    {
        first=last=t;
    }
    else{
    while(p!=NULL)
    {
        p=p->next; 
    }
    last=p;
    last->next=t;
    last=t;
    }

}

void sorted_insert(struct Node *p,int key)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->next=NULL;
    

    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p && p->data<key)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int is_sorted(struct Node *p)
{
    int x=first->data;
    while(p!=NULL)
    {
        if(p->data<x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

int isLoop(struct Node *f)
{
    struct Node *p,*q;

    p=q=f;

    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    return (p==q)?1:0;
}

int LL_INT(struct Node* p)
{
    int number=0,i=0;
    
    while(p!=NULL)
    {
        number+=p->data*pow(10,i);
        i++;
    }
    return number;
}


int main()
{
    // struct Node *t1,*t2;

    int A[]={1,2,3,4,5};
    create(A,5);

    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;

    printf("%d\n",LL_INT(first));

    
    return 0;
}




   