#include<stdio.h>
#include<conio.h>
void linear(int a[10],int n,int item);
void main()
{
int a[10],n,i,item;
printf("enter the size of an array");
scanf("%d",&n);
printf("enter the array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the item to search");
scanf("%d",&item);
linear(a,n,item);
}
void linear(int a[10],int n,int item)
{
int i,flag=0;
for(i=0;i<=n;i++)
{
if(a[i]==item)	
{
printf("found at %d position\n",i+1);
flag=1;
break;
}
}
if(flag==0)
{	
printf("not found");
}
}
