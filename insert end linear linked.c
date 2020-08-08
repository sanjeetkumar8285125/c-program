//insertion at the end
#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
node *head,*tmp,*q;
void insertend(node *head);
void display(node *head);
void createlist()
{
	int n,i,m;
printf("how many node you want");
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
insertend(head);
}
void insertend(node *head)
{
node *q,*newnode;
newnode=(node*)malloc(sizeof(node));
printf("enter element to be inserted");
scanf("%d",&newnode->info);
newnode->next=NULL;
if(head==NULL)
head=newnode;
else
{
q=head;
while(q->next!=NULL)
q=q->next;
q->next=newnode;
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
