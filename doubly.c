#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node ));
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int length(struct Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index<0 || index>length(first))
    return;

    if(index==0)
    {
        first->prev=t;
        t->prev=NULL;
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        if(p->next)
        {
            p->next->prev=t;
        }
        p->next=t;
    }
}

int delete(struct Node *p,int index)
{
    int x=-1;

    if(index<1 || index>length(first))
    {
    return -1;
    }
    if(index==1)
    {
       first=p->next;
       if(first)first->prev=NULL;
       x=p->data;
       free(p);
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}

void reverse(struct Node *p)
{
    struct Node *temp;
   
    while(p!=NULL)
    {
      temp=p->next;
      p->next=p->prev;
      p->prev=temp;
      p=p->prev;
      if(p!=NULL && p->next==NULL)
      {
        first=p;
      }
    }
}



int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    reverse(first);
    display(first);

    return 0;
}