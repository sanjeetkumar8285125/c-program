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
void insert_desired(node *head);
void display(node *head);
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
insert_desired(head);
}
void insert_desired(node *head)
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
