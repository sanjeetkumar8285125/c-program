//creation of  number of node
#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
node *head;
node *first,*second,*third;
void display(node *head);
void createlist()
{
first=(node*)malloc(sizeof(node));
second=(node*)malloc(sizeof(node));
third=(node*)malloc(sizeof(node));
first->info=5;
first->next=second;
second->info=10;
second->next=third;
third->info=20;
third->next=NULL;
head=first;
display(head);
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
