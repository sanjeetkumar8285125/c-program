#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max_size 5
int queue[max_size],front=-1,rear=-1;
void insert();
void delete();
void display();
int main()
{
int choice;
do
{
printf(".......queue....\n");
printf("1.insert \n");
printf("2.delete \n");
printf("3.display \n");
printf("4.exit \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: insert();
break;
case 2: delete();
break;
case 3: display();
break ;
case 4: exit(0);
break;
default:
printf("invalid choice");
break;
}
}
while(choice!=4);
}
void insert()
{

int item;
if(rear==(max_size-1))
{
printf("queue overflow");
}
else
{
printf("enter element to be inserted");
scanf("%d",&item);
rear=rear+1;
queue[rear]=item;
if(front==-1)
{
front=0;
}
}
}
void delete()
{
int item;
if(front==-1)
{
printf("queue underflow");
}
item=queue[front];
printf("the deleted element=%d\n",item);
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=front+1;
}
}
void display()
{
int i;
if(front==-1)
{
printf("queue is empty\n");
}
else
{
printf("\n the queue element are:\n");
for(i=front;i<=rear;i++)
{
printf("%d\t",queue[i]);
}
}
printf("\n");
}
