#include <stdio.h>
#include <stdlib.h>
int *a, n;
int count,cc=0;

void input8();
void output8();
void scan(int);

int main()
{
	scanf("%d",&n);
	a=new int [n];
	
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for(int i=n;i>=2;i--)
	{
		count=0;
		scan(i);
		if (count==0) break;
	}
	output8();
	return 0;
}

void input8()
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	return;
}


void output8()
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n==>%d",cc);
	return;
}

void scan(int f)
{
	int i,temp;
	for(i=0;i<=f-2;i++)
	{
		cc++;
		if(a[i]>a[i+1])
		{
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
			count++;
		}
	}

	return;	
}
