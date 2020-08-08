#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct nodetype
{
struct nodetype *next;
struct nodetype *prev;
int info;
}node;
node *head,*tail,*tmp;
void delete_desired(node *head);
void transeverse_order(node *head);
void createnodes()
{
int n,m,i;
printf("how many nodes you want:-");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter element");
scanf("%d",&m);
tmp=(node *)malloc(sizeof(node));
tmp->info=m;
tmp->next=NULL;
tmp->prev=NULL;
if(head==NULL)
{
head=tail=tmp;
}
else
{
tmp->prev=tail;
tail->next=tmp;
tail=tmp;
}
}
delete_desired(head);
}
void delete_desired(node *head)
{
node *loc,*ptr,*q;
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
(ptr->next)->prev=loc;
free(ptr);
}
}
}
q=q->next;
}
}
traverse_order(head);
}
void traverse_order(node *head)
{
node *ptr;
ptr=head;
 printf("\n traverse order :-\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->info);
ptr=ptr->next;
}
}
void main()
{
	createnodes();
}
