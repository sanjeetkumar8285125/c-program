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
void deletebeg(node *head);
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
deletebeg(head);
}
void deletebeg(node *head)
{
    node *ptr;
if(head==NULL)
printf("no node to delete");
else if(head==tail)
{
ptr=head;
head=tail=NULL;
free(ptr);
}
else
{
ptr=head;
head=ptr->next;
(ptr->next)->prev=NULL;
ptr->next=NULL;
free(ptr);
}
traverse_order(head);
}
void traverse_order(node *head)
{
node *ptr;
ptr=head;
 printf("In transerverse order :-\n");
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
