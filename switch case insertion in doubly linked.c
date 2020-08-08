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
void insertbeg(node *head);
void insertend(node *head);
void insert_after(node *head);
void insert_before(node *head);
void display(node *head);
int main()
{
    createlist();
int choice;
do
{
printf("we have five choice \n");
printf("1.Insertion of node in beginning \n");
printf("2.Insertion of node in end \n");
printf("3.insertion of node after the desired element \n");
printf("4.insertion of node before the desired element \n");
printf("5.exit \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: insertbeg(head);
break;
case 2: insertend(head);
break;
case 3: insert_after(head);
break;
case 4: insert_before(head);
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

void insertbeg(node *head)
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

void insertend(node *head)
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
void insert_after(node *head)
{
node *ptr,*newnode;
int elt;
newnode=(node *)malloc(sizeof(node));
ptr=head;
printf("enter the element to be searched");
scanf("%d",&elt);
while(ptr!=NULL)
{
if(ptr==NULL)
printf("list is empty");
else if(ptr->info==elt)
{
printf("enter the element to insert");
scanf("%d",&newnode->info);
newnode->next=ptr->next;
ptr->next->prev=newnode;
ptr->next=newnode;
newnode->prev=ptr;
break;
}
else
ptr=ptr->next;
}
display(head);
}
void insert_before(node *head)
{
node *ptr,*newnode;
int elt;
newnode=(node *)malloc(sizeof(node));
ptr=head;
printf("enter the element to be searched");
scanf("%d",&elt);
while(ptr!=NULL)
{
if(ptr==NULL)
printf("list is empty");
else if(ptr->info==elt)
{
printf("enter the element to insert");
scanf("%d",&newnode->info);
newnode->next=ptr;
newnode->prev=ptr->prev;
ptr->prev->next=newnode;
ptr->prev=newnode;
break;
}
else
ptr=ptr->next;
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


