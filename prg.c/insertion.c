#include<stdio.h>
void main()
{
int arr[25],i,n,p,el;
printf("Enter the size:");
scanf("%d",&n);
for (i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the position");
scanf("%d",&p);
printf("Enter the element ");
scanf("%d",&el);
n=n+1;
for(i=n;i>=p-1;i--)
{
arr[i+1]= arr[i];
}
arr [p-1]=el;
printf("the new array\n");
for(i=0;i<n;i++)
{
printf("%d\n",arr[i]);
}
}
