#include <stdio.h>
#include <algorithm>
using namespace std ;
bool compare(int a , int b)
{
	return a<b;
}

int main()
{
	int n;
	int a[100];
	printf("input the n of the int \n");
	while(scanf("%d",&n)!=EOF)
	{
		printf("input the number!!\n");
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		/*
		//bubble sort o(n^2)

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
					int tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
				}
			}
		}
		*/

		//quick sort
		printf("using quick sort\n");
		sort(a,a+n,compare);
		for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}
