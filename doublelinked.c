#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct nodetype
{
struct nodetype *prev;
struct nodetype *next;
int info;
}node;
node *head,*tail;
node *first,*second,*third;
void transverse_order(node *head);
void createlist()
{
first=(node*)malloc(sizeof(node));
second=(node*)malloc(sizeof(node));
third=(node*)malloc(sizeof(node));
first->info=5;
first->prev=NULL;
first->next=second;
second->info=10;
second->prev=first;
second->next=third;
third->info=15;
third->prev=second;
third->next=NULL;
head=first;
tail=third;
transverse_order(head);
}
void transverse_order(node *head)
{
node *ptr;
ptr=head;
while(ptr!=NULL)
{
printf("%d\n",ptr->info);
ptr=ptr->next;
}
}
void main()
{
createlist();
}
