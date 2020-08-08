#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
typedef struct nodetype
{
struct nodetype *next;
struct nodetype *prev;
int info;
}node;
node *head,*tail,*tmp;
void delete_beg(node *head);
void delete_end(node *head);
void delete_after(node *head);
void delete_before(node *head);
void traverse_order(node *head);
int main()
{
createlist();
int choice;
do
{
printf("we have five choice \n");
printf("1.Deletion of node in beginning \n");
printf("2.Deletion of node in end \n");
printf("3.Deletion of node after the desired position \n");
printf("4.Deletion of node before the desired position \n");
printf("5.exit \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: delete_beg(head);
break;
case 2: delete_end(head);
break;
case 3: delete_after(head);
break;
case 4: delete_before(head);
break;
case 5: exit(0);
break;
default:
printf("invalid choice");
break;
}
}
while(choice!=5);
}
void createlist()
{
int n,m,i;
printf("how many nodes you want: ");
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
}
void delete_beg(node *head)
{
int item;
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
item=head->info;
head=ptr->next;
(ptr->next)->prev=NULL;
ptr->next=NULL;
free(ptr);
printf("\nthe deleted data is %d \n",item);
}
traverse_order(head);
}
void delete_end(node *head)
{
int item;
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
ptr=tail;
item=tail->info;
tail=ptr->prev;
tail->next=NULL;
ptr->prev=NULL;
free(ptr);
printf("\nthe deleted data is %d \n",item);
}
traverse_order(head);
}
void delete_after(node *head)
{
node *loc,*ptr,*q;
int elt;
if(head==NULL)
{
printf("no node to delete");
}
else
{
printf("enter the element to searched ");
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
traverse_order(head);
}
void delete_before(node *head)
{
node *loc,*ptr,*q;
int elt;
if(head==NULL)
{
printf("no node to delete");
}
else
{
printf("enter the element to searched: ");
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
if(loc->prev==NULL)
{
printf("no node to delte");
}
else
{
ptr=loc->prev;
loc->prev=ptr->prev;
(ptr->prev)->next=loc;
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
printf("\nIn traverse order :-\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->info);
ptr=ptr->next;
}
}
