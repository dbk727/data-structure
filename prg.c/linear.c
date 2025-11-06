#include<stdio.h>
void main()
{
int a[25],i,n,key,flag=0;
printf("Enter the limit:");
scanf("%d",&n);
printf("Enter the array element:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the key to be searched:");
scanf("%d",&key);
for(i=0;i<n;i++)
{
flag=1;
break;
}
if(flag==1)
{
printf("Search successfull,element%d  found at %d",key,i+1);
}
else 
{
printf("Search unsuccessfull,Element not found");
}
}

