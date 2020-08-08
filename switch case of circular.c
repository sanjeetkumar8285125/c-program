#include<stdio.h>
#include<conio.h>
#include<malloc.h>
# define MAX 5
void insert();
void display();
void del();
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void main()
{
int choice;
while(1)
{
printf("\n---------- MENU FOR CIRCULAR QUEUE ----------------\n");
printf("1.Insert.\n");
printf("2.Delete.\n");
printf("3.Display.\n");
printf("4.Quit.\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
insert();
break;
case 2 :
del();
break;
case 3:
display();
break;
case 4:
exit(1);
default:
printf("\nINVALID CHOICE TRY AGAIN\n");
}
}
}
void insert()
{
int added_item;
printf("\nEnter the element for insertion in Circular Queue : ");
scanf("%d", &added_item);
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("Queue Overflow\n");
return;
}
if (front == -1)
{
front = 0;
rear = 0;
}
else
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
cqueue_arr[rear] = added_item ;
}
void del()
{
if (front == -1)
{
printf("Queue Underflow\n");
return ;
}
printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
if(front == MAX-1)
front = 0;
else
front = front+1;
}
void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is empty\n");
return;
}
printf("\n------Queue elements-----------\n\n");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d \t",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos <= MAX-1)
{
printf("%d \t",cqueue_arr[front_pos]);
front_pos++;
}
front_pos = 0;
while(front_pos <= rear_pos)
{
printf("%d \t",cqueue_arr[front_pos]);
front_pos++;
}
}
printf("\n\n");
}
