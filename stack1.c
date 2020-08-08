#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max_size 5
int stack[max_size],top=-1;
void push();
void pop();
void peep();
void display();
int main()
{
int choice;
do
{
printf(".......stack....\n");
printf("1.push \n");
printf("2.pop \n");
printf("3.peep \n");
printf("4.display \n");
printf("5.exit \n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: push();
break;
case 2: pop();
break;
case 3: peep();
break;
case 4: display();
break ;
case 5: exit(0);
break;
default:
printf("invalid choice");
break;
}
}
while(choice!=5);
}
void push()
{
int item;
if(top==(max_size-1))
{
printf("\n stack overflow");
}
else
{
printf("enter the element to be inserted");
scanf("%d",&item);
top=top+1;
stack[top]=item;
}
}
void pop()
{
int item;
if(top==-1)
{
printf("stack underflow");
}
else
{
item=stack[top];
top=top-1;
printf("the popped element %d \n",item);
}
}
void peep()
{
if(top==-1)
{
printf("stack is empty \n");
}
else
{
printf("the topmost element is %d\n",stack[top]);
}
}
void display()
{
int i;
if(top==-1)
{
printf("\n stack is empty");
}
else
{
printf("\n stack elements are:-\n");
for(i=top;i>=0;i--)
{
printf("%d\n",stack[i]);
}
}
}
