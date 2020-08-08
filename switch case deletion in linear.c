#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct nodetype
{
	int info;
	struct nodetype *next;
}node;
node *q,*tmp,*head;
void delete_beg(node *head);
void delete_desired(node *head);
void delete_end(node *head);
void display(node *head);
void main()
{
    createlist();
    int choice;
    do
    {
printf("\nyou have four choices\n");
printf("1.deletion of node in the beginning\n");
printf("2.deletion of node after the desired position\n");
printf("3.deletion at the end\n");
printf("4.exit\n");
printf("\nWhich action you want to perform :-  ");
scanf ("%d",&choice);
switch(choice)
{
case 1:	delete_beg(head);
break;
case 2: delete_desired(head);
break;
case 3: delete_end(head);
	 break;
case 4: exit(1);
break;
default:
printf("wrong choices");
 }
}
while(choice!=4);
}
void createlist()
{
int i,n,m;
printf("how many nodes you want");
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
}
void delete_beg(node *head)
{
int item;
node *ptr;
if(head==NULL)
printf("no node to delete");
else
{
ptr=head;
item=head->info;
head=ptr->next;
free(ptr);
ptr->next=NULL;
printf("the deleted element is %d\n",item);
}
display(head);
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
printf("enter the element to searched  ");
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
void delete_end(node *head)
{
    node *ptr;
if(head==NULL)
printf("no node to delete");
else
{
if(head->next==NULL)
{
ptr=head;
head=NULL;
free(ptr);
}
else
{
q=head;
ptr=q->next;
while(ptr->next!=NULL)
{
q=ptr;
ptr=ptr->next;
}
q->next=NULL;
free(ptr);
}
}
display(head);
}
void display(node *head)
{
node *ptr;
ptr=head;
printf("\nthe elements are:-");
while(ptr!=NULL)
{
printf("\n%d",ptr->info);
ptr=ptr->next;
}
}
