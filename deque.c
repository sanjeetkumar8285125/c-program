//representing a stack using a linked list
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
void enquefront(node *head);
void enquerear(node *head);
void dequefront(node *head);
void dequerear(node *head);
void display(node *head);
int main()
{
    createlist();
int choice;
do
{
printf("we have five choice \n");
printf("1.enquefront \n");
printf("2.enquerear \n");
printf("3.dequefront \n");
printf("4.dequerear \n");
printf("5.exit \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: enquefront(head);
break;
case 2: enquerear(head);
break;
case 3: dequefront(head);
break;
case 4: dequerear(head);
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
}

void enquefront(node *head)
{
    int item;
node *newnode;
newnode=(node *)malloc(sizeof(node));
    printf("enter the element to insert");
    scanf("%d",&newnode->info);
    if(head==NULL)
    {
    head=newnode;
    newnode->next=newnode->prev=NULL;
    tail=newnode;
    }
    else
    {
        item=newnode->info;
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
      head=newnode;
printf("the inserted element is %d \n",item);
    }
    display(head);
}

void enquerear(node *head)
{
    int item;
node *newnode;
newnode=(node *)malloc(sizeof(node));
    printf("enter the element to insert");
    scanf("%d",&newnode->info);
    if(head==NULL)
    {
    head=newnode;
    newnode->next=newnode->prev=NULL;
    tail=newnode;
    }
    else
    {
        item=newnode->info;
    newnode->next=NULL;
    newnode->prev=tail;
    tail->next=newnode;
      tail=newnode;
      printf("the inserted data is %d \n",item);
    }
    display(head);
}

void dequefront(node *head)
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
printf("the deleted data is %d \n",item);
}
display(head);
}
void dequerear(node *head)
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
printf("the deleted data is %d \n",item);
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
printf("\n");
}


