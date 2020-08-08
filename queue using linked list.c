//representing a queue using a linked list
#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
#include<process.h>
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
node *head,*tmp,*q;
void push(node *head);
void pop(node *head);
void display(node *head);
int main()
{
createlist();
int choice;
do
{
printf("we have four choice \n");
printf("1.push \n");
printf("2.pop \n");
printf("3.display \n");
printf("4.exit \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: push(head);
break;
case 2: pop(head);
break;
case 3: display(head);
break;
case 4: exit(0);
break;
default:
printf("invalid choice");
break;
}
}
while(choice!=4);
}
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
}
void push(node *head)       //insertion at the end
{
node *newnode;
newnode=(node *)malloc(sizeof(node));
printf("enter the element to insert");
scanf("%d",&newnode->info);
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
}
else
{
q=head;
while(q->next!=NULL)
q=q->next;
q->next=newnode;
}
}

void pop(node *head)
{
    int item;
    node *ptr;
    if(head==NULL)
        printf("no node to delete");
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        free(ptr);
    }
    else
    {

        ptr=head;
        item=head->info;
        head=ptr->next;
        free(ptr);
        printf("deleted element is %d\n",item);
    }
}
void display(node *head)
{
node *ptr;
ptr=head;
printf("the elements are:- ");
while(ptr!=NULL)
{
printf("\n%d",ptr->info);
ptr=ptr->next;
}
printf("\n");
}
