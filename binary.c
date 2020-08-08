#include<stdio.h>
#include<conio.h>
void binary(int a[10],int n,int item);
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
binary(a,n,item);
}
void binary(int a[10],int n,int item)
{
int l=0,u=n-1,m;
while(l<=u)
{
m=l+u;
if(a[m]==item)
{
printf("found at %d position\n",m+1);
exit();
}
else if(item>a[m])
l=m+1;
else
u=m-1; 
}
printf("not found");
}

