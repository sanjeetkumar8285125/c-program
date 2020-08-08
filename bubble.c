void bubble(int a[10],int n);
void main()
{
int a[10],n,i;
printf("enter the size of an array");
scanf("%d",&n);
printf("enter element");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
bubble(a,n);
}
void bubble(int a[10],int n)
{
int pass,i,temp;
for(pass=1;pass<n;pass++)
{
for(i=0;i<n-pass;i++)
{
if(a[i]>a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
}
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
}
