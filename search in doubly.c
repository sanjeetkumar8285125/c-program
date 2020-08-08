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
void delete_end(node *head);
void transeverse_order(node *head);
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
search(head);
}
void search(node *head)
{
int elt;
node *loc,*ptr;
printf("enter the element to be searched");
scanf("%d",&elt);
ptr=head;
while(ptr!=NULL)
{
if(ptr->info==elt)
{
loc=ptr;
printf("found at %d",ptr);
break;
}
ptr=ptr->next;
}

}

void main()
{
	createnodes();
}
