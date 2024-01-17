#include <stdio.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head;

void create(int A[],int n)
{
    struct Node *t,*last;

    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->prev=head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
       last->next=t;
       t->prev=last;
       
    }

    

}

int main()
{

    return 0;
}