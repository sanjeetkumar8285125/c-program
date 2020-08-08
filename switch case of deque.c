//representing a stack using a linked list
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
struct node
    {
    	int data;
    	struct node *prev,*next;
    };
    struct node *head=NULL,*tail=NULL;
    struct node *createnode(int data)
    {
    	struct node *newnode=(struct node*)malloc(sizeof(struct node));
    	newnode->data=data;
    	newnode->next=newnode->prev=NULL;
    	return(newnode);
    }
    void creates();
     void enquefront(int data);
     void enquerear(int data);
     void dequefront(int data);
     void dequerear(int data);
     void display(int data);
int main()
{
creates();
int choice;
do
{
printf("we have four choice \n");
printf("1.enquefront \n");
printf("2.enquerear \n");
printf("3.dequefront \n");
printf("4.dequerear \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: enquefront(data);
break;
case 2: enquerear(data);
break;
case 3: dequefront(data);
break ;
case 4: dequerear(data);
break;
case 5: display(data);
break;
case 6: exit(0);
break;
default:
printf("invalid choice");
break;
}
}
while(choice!=6);
}
    void creates()
    {
    head=createnode(0);
	tail=createnode(0);
	head->next=tail;
	tail->prev=head;
    }
    
    void enquefront(int data)
    {
struct node *newnode,*temp;
newnode=createnode(data);
temp=head->next;
head->next=newnode;
newnode->prev=head;
newnode->next=temp;
temp->prev=newnode;
    }
    
    void enquerear(int data)
    { 
	struct node *newnode,*temp;
	newnode=createnode(data);
	temp=tail->prev;
	tail->prev=newnode;
	newnode->next=tail;
	newnode->prev=tail;
	temp->next=newnode;
    }
    void dequefront(int data)
    {
    	int item;
    	struct node *temp;
    	if(head->next==tail)
    	{
    		printf("queue is empty");
    	}
    	else
    	{
    		temp=head->next;
    		item=temp->data;
    		head->next=temp->next;
    	(temp->next)->prev=head;
    	free(temp);
    	printf("deleted data is %d\n",item);
    	}
    	return 0;
    }
    void dequerear(int data)
    {
    	int item;
    	struct node *temp;
    	if(tail->prev==head)
    	{
    		printf("queue is empty");
    	}
    		else
    		{
    			temp=tail->prev;
    			item=temp->data;
    			tail->prev=temp->prev;
    			temp->prev->next=tail;
    			free(temp);
    			printf("deleted data is %d\n",item);
    		}
	//return 0;
    		}
    		void display(int data)
    		{
    			struct node *temp;
    			if(head->next==tail)
    			{
    		printf("queue is empty");
    			}
    			else
    			{
    				printf("list element ar \n");
    				temp=head->next;
    				while(temp!=tail)
    				{
    					printf("%d\t",temp->data);
    					temp=temp->next;
    				}
    			}
    		}
    			
 	
