#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
node *head,*tmp,*q;
void delete_desired(node *head);
void display(node *head);
void createlist()
{
	int n,i,m;
printf("how many nodes you want to insert");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter element");
scanf("%d",&m);
tmp=(node*)malloc(sizeof(node));
tmp->info=m;
tmp->next=NULL;
if(head==NULL)
{
head=tmp;
tmp->next=NULL;
}
else
{
q=head;
while(q->next!=NULL)
q=q->next;
q->next=tmp;
}
}
delete_desired(head);
}
void delete_desired(node *head)
{
node *loc,*ptr;
int elt;
if(head==NULL)
{
printf("no node to delete");
}
else
{
    printf("enter the element to searched");
    scanf("%d",&elt);
    q=head;
    while(q->next!=NULL)
    {
        if(q->info==elt)
        {
        loc=q;
    if(loc==NULL)
    {
        printf("not found");
    }
    else
    {
        if(loc->next==NULL)
        {
            printf("no node to delte");
        }
    else
    {
      ptr=loc->next;
        loc->next=ptr->next;
        free(ptr);
    }
}
        }
q=q->next;
}

}

display(head);
}


void display(node *head)
{
node *ptr;
ptr=head;
while(ptr!=NULL)
{
printf("\n%d",ptr->info);
ptr=ptr->next;
}
}
void main()
{
createlist();
}
