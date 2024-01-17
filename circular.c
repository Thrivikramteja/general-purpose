#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*head;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    } while (h!=head);
    printf("\n");
}

void Rdisplay(struct Node *h)
{
    static int flag=0;
    if(h!=head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        Rdisplay(h->next);
    }
    flag=0;
}

int length(struct Node *p)
{
    int count=0;
   do
   {
    count++;
    p=p->next;
   } while (p!=head);
   
   return count;
    
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index<0 || index>length(p));

    if(index==0)
    {
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
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

void delete(struct Node *p,int index)
{
    int x;
    struct Node *q;

    if(index<0 || index>length(head))
    {
        return;

    }

    if(index==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        x=p->data;
        if(head==p)
        {
            free(head);
            head==NULL;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else 
    {
       for(int i=0;i<index-2;i++)
       {
        p=p->next;
       }
       q=p->next;
       p->next=q->next;
       x=q->data;
       free(q);
    }
}



int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);

    delete(head,4);
    
    Rdisplay(head);

    return 0;
}