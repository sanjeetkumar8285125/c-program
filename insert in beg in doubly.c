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
void insertbeg(node *head);
void traverse(node *head);
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
insertbeg(head);
}
void insertbeg(node *head)
{
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
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
      head=newnode;

    }
    traverse(head);
}
void traverse(node *head)
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
