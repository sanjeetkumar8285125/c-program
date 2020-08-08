#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
node *head,*tmp,*q;
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
}
void display(node *head)
{
node *ptr;
ptr=head;
while(ptr!=NULL)
{
printf("\n %d",ptr->info);
ptr=ptr->next;
}
}
void main()
{
createlist();
}

