#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
int priority;
int info;
struct node *link;
}*front=NULL;
void insert();
void delete();
void display();
int main()
{
int choice,item,item_priority;
while(1)
{
printf(" 1.Insert\n 2. Delete \n 3. Display\n 4. exit \n");
printf("enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: insert();
break;
case 2: delete();
break;
case 3: display();
break;
case 4: exit(1);
break;
default:
printf("Invalid choice");
}
}
}
void insert()
{
struct node *tmp,*q;
int added_item,item_priority;
tmp = (struct node *)malloc(sizeof(struct node));
printf("Input the data to be added in the queue : ");
scanf("%d",&added_item);
printf("Enter its priority : ");
scanf("%d",&item_priority);
printf("\n");
tmp->info = added_item;
tmp->priority = item_priority;
if( front == NULL || item_priority < front->priority )
{
tmp->link = front;
front = tmp;
}
else
{
q = front;
while( q->link != NULL && q->link->priority <= item_priority )
q=q->link;
tmp->link = q->link;
q->link = tmp;
}
}
void delete()
{
struct node *tmp;
int item;
if(front==NULL)
{
printf("queue underflow");
exit(1);
}
else
{
tmp=front;
item=tmp->info;
front=front->link;
free(tmp);
}
printf("deleted item is %d\n",item);
}

void display()
{
struct node *ptr;
ptr=front;
if(front==NULL)
{
printf("Queue is empty\n");
}
else
{
    printf("\n");
printf("Priority\tData\n\n");
while(ptr!=NULL)
{
printf("%d \t\t%d\n\n",ptr->priority,ptr->info);
ptr = ptr->link;
}
}
}
