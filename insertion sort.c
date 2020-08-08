void insert(int a[10],int n);
void main()
{
int a[10],n,i;
printf("enter the size of an array");
scanf("%d",&n);
printf("enter element");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
insert(a,n);
}
void insert(int a[10],int n)
{
int i,j,temp;
for(i=1;i<n;i++)
{
temp=a[i];
for(j=i-1;j>=0 && temp<a[j];j--)
a[j+1]=a[j];
a[j+1]=temp;
}
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
}
