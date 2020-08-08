//creation of  n number of node
#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
typedef struct nodetype
{
int info;
struct nodetype *next;
}node;
node *head,*tmp,*q;
void deletebeg(node *head);
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
deletebeg(head);
}
void deletebeg(node *head)
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
void display(node *head)
{
node *ptr;
ptr=head;
printf("the elements are:-");
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
