#include<stdio.h>
#include<conio.h>
#include<malloc.h>
# define MAX 5
void CQarray();
void insert1();
void display1();
void del1();

void CQlink();
void insert();
void del();
void display();

int cqueue_arr[MAX];
int front1 = -1;
int rear1 = -1;

struct node
{
int info;
struct node *link;
}*rear=NULL;

void main()
{
          int n;
          while(1)
          {
printf("\n-------------------------- MENU FOR CIRCULAR QUEUE------------------------\n");
                   printf("\n1.CIRCULAR QUEUE USING ARRAY.\n\n");
                   printf("2.CIRCULAR QUEUE USING LINKED LIST.\n\n");
                   printf("3.EXIT.\n\n");
                   printf("Enter your choice :");
                   scanf("%d",&n);
                   switch(n)
                   {
                             case 1:
                                      CQarray();
                                      break;
                             case 2:
                                      CQlink();
                                      break;
                             case 3:
                                      exit(1);
                             default:
printf("\nINVALID CHOICE TRY AGAIN!!!!!!!!!!!!!\n");
                   }
          }
}

void CQarray()
{
          int choice;
printf("\n------------------ CIRCULAR QUEUE USING ARRAY --------\n\n");
          while(1)
          {
printf("\n\n----------------- MENU FOR CIRCULAR QUEUE ----------------------\n\n");
                   printf("1.Insert.\n\n");
                   printf("2.Delete.\n\n");
                   printf("3.Display.\n\n");
                   printf("4.Quit.\n\n");
                   printf("Enter your choice : ");
                   scanf("%d",&choice);
                   switch(choice)
                   {
                             case 1 :
                                      insert1();
                                      break;
                             case 2 :
                                      del1();
                                      break;
                             case 3:
                                      display1();
                                      break;
                             case 4:
                                      exit(1);
                             default:
printf("\nINVALID CHOICE TRY AGAIN!!!!!!!!!!!!!\n");
                   }
          }
}

void insert1()
{
          int added_item;
          if((front1 == 0 && rear1 == MAX-1) || (front1 == rear1+1))
          {
printf("\n\n---------------------------------------------------------\n\n");
                   printf("Queue Overflow......don't insert any more element\n");
printf("\n\n---------------------------------------------------------\n\n");
                   return;
          }
          if (front1 == -1)
          {
                   front1 = 0;
                   rear1 = 0;
          }
          else
                   if(rear1 == MAX-1)
                   rear1 = 0;
          else
                   rear1 = rear1+1;
printf("\n\nEnter the element for insertion in Circular Queue : ");
                   scanf("%d", &added_item);
                   cqueue_arr[rear1] = added_item ;
}

void del1()
{
          if (front1 == -1)
          {
printf("\n\n---------------------------------------------------------\n\n");
printf("Queue Underflow.........can't delete any more element\n");
printf("\n\n---------------------------------------------------------\n\n");
                   return ;
          }
          printf("\n\n---------------------------------------------------------\n\n");
          printf("Element deleted from queue is : %d\n",cqueue_arr[front1]);
          printf("\n\n---------------------------------------------------------\n\n");
          if(front1 == rear1)
          {
                   front1 = -1;
                   rear1=-1;
          }
          else
                   if(front1 == MAX-1)
                             front1 = 0;
                   else
                             front1 = front1+1;
}

void display1()
{
          int front_pos = front1,rear_pos = rear1;
          if(front1 == -1)
          {
printf("\n\n---------------------------------------------------------\n\n");
printf("Queue is empty..............there is no element to be displayed\n");
printf("\n\n---------------------------------------------------------\n\n");
                   return;
          }
          printf("\n----------------------Queue elements----------------------\n\n");
          if( front_pos <= rear_pos )
          while(front_pos <= rear_pos)
          {
                   printf("%d ",cqueue_arr[front_pos]);
                   front_pos++;
          }
          else
          {
                   while(front_pos <= MAX-1)
                   {
                                      printf("%d ",cqueue_arr[front_pos]);
                                      front_pos++;
                   }
                   front_pos = 0;
                   while(front_pos <= rear_pos)
                   {
                             printf("%d ",cqueue_arr[front_pos]);
                             front_pos++;
                   }
          }
          printf("\n\n");
}

void CQlink()
{
          int choice;
printf("\n------------------ CIRCULAR QUEUE USING LINKED LIST ---------\n\n");
          while(1)
          {
printf("\n\n----------------- MENU FOR CIRCULAR QUEUE ----------------------\n\n");
                   printf("1.Insert.\n\n");
                   printf("2.Delete.\n\n");
                   printf("3.Display.\n\n");
                   printf("4.Quit.\n\n");
                   printf("Enter your choice : ");
                   scanf("%d",&choice);
                   switch(choice)
                   {
                             case 1:
                                      insert();
                                      break;
                             case 2:
                                      del();
                                      break;
                             case 3:
                                      display();
                                      break;
                             case 4:
                                 exit(0);
                             default:
printf("\nINVALID CHOICE TRY AGAIN!!!!!!!!!!!!!\n");
                   }
          }
}

void insert()
{
          int num;
          struct node *q,*tmp;
          printf("\nEnter the element for insertion in Circular Queue : ");
          scanf("%d",&num);
          tmp= malloc(sizeof(struct node));
          tmp->info = num;
          if(rear == NULL)
          {
                   rear = tmp;
                   tmp->link = rear;
          }
          else
          {
                   tmp->link = rear->link;
                   rear->link = tmp;
                   rear = tmp;
          }
}

void del()
{
          struct node *tmp,*q;
          if(rear==NULL)
          {
                   printf("\n----------------------------------------------------\n");
                   printf("Queue underflow..........no element left to be deleted\n");
                   printf("\n----------------------------------------------------\n");
                   return;
          }
          if( rear->link == rear )
          {
                   tmp = rear;
                   rear = NULL;
                   free(tmp);
                   return;
          }
          q=rear->link;
          tmp=q;
          rear->link = q->link;
printf("\n----------------------------------------------------------------------\n");
          printf("Deleted element is %d\n",tmp->info);
printf("\n---------------------------------------------------------------------\n");
          free(tmp);
}

void display()
{
          struct node *q;
          if(rear == NULL)
          {
printf("\n-------------------------------------------------------------------\n");
printf("Queue is empty......there is no element to be displayed\n");
printf("\n------------------------------------------------------------------\n");
                   return;
          }
          q = rear->link;
printf("\n--------------------------- Queue ---------------------------------\n\n");
          while(q != rear)
          {
                   printf("%d ", q->info);
                   q = q->link;
          }
          printf("%d\n",rear->info);
}
