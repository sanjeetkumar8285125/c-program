#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
typedef struct nodetype
{
	int info;
	struct nodetype *next;
}node;
node *q,*tmp,*head;
void insertbeg();
void insertbeg1();
void insertend();
void display(node *head);
void main()
{
    int i;
    do
    {
	printf("you have four choices\n");
	printf("1.insertion of node in the beginning\n");
	printf("2.insertion of node after the desired element\n");
	printf("3.insertion at the end\n");
	printf("4.exit\n");
	printf("Which action you want to perform :-  ");
 scanf ("%d",&i);
 switch(i)
 {
 	case 1:	createlist();
	 insertbeg();
	 break;
	 case 2:createlist();
	 insertbeg1();
	 break;
	 case 3:createlist();
	 insertend();
	 break;
	 case 4: exit(1);
	 break;
	 default:
	 printf("wrong choices");
 }
    }
 while(i!=4);
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


void insertbeg()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("enter element u want to insert");
	scanf("%d",&newnode->info);
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	display(head);
}
void insertbeg1()
{
	int elt;
	node *newnode,*ptr;
	newnode=(node*)malloc(sizeof(node));
	ptr=head;
	printf("enter element to be searched");
	scanf("%d",&elt);
	while(ptr!=NULL)
	{
		if(ptr->info==elt)
		{
			printf("enter the elemnt to be inserted");
			scanf("%d",&newnode->info);
			newnode->next=ptr->next;
			ptr->next=newnode;
		break;
		}
		else
		ptr=ptr->next;

	}
	display(head);
}
 void insertend()
{
	node *q,*newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("enter element to be inserted");
	scanf("%d",&newnode->info);
	newnode->next=NULL;
	if(head==NULL)
	head=newnode;
	else
	{
		q=head;
		while(q->next!=NULL)
		q=q->next;
		q->next=newnode;
	}
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
