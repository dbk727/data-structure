#include<stdio.h>
int main()
{
int i,j,k,a[50],b[50],c[100],n,m;
printf("Enter the first array size");
scanf("%d",&m);
printf("Enter the elements of first array:");
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the second  array size:");
scanf("%d",&n);
for(j=0;j<n;j++)
{
scanf("%d",&b[j]);
}
i=0;
j=0;
k=0;
while(i<m && j<n)
{
	if(a[i]<b[j]){
		c[k++]=a[i++];
	}
	else
	{
	c[k++]=b[j++];
	}
}
while(i<m)
{
c[k++]=a[i++];
}
while(j<n)
{
c[k++]=b[j++];
}
printf("Merged array:\n");
for(i=0;i<m+n;i++)
{
printf("%d\n",c[i]);
}
return 0;
}
