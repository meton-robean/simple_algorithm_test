#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
struct Student
{
	char no[100];
	char name[100];
	int age;
	char  sex[5];
	bool operator <(const Student & s2) const
	{
		return strcmp(no,s2.no)<0; //用于sort的降序
	}
}student[100];


int main()
{
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		for(int i=0;i<m;i++)
		{
			scanf("%s%s%s%d",student[i].no,student[i].name,student[i].sex,&student[i].age);

		}
		sort(student,student+m);//descend sort 
		int n;
		scanf("%d",&n);
		while(n--!=0)
		{
			int ans=-1;
			char x[100];
			scanf("%s",x);
			int top=m-1;
			int base=0;
			int mid;
			while(top>=base)//bin sort
			{
				mid=(top+base)/2;
				int flag=strcmp(student[mid].no,x);
				if(0==flag)
				{
					ans=mid;
					break;
				}
				else if(flag>0)
				{
					top=mid-1;
				}else{
					base=mid+1;
				}
			} 

			if(ans!=-1)
			{
				printf("%s %s %s %d \n",student[ans].no,student[ans].name,student[ans].sex,student[ans].age );

			}else{
				printf("No Answer!\n");
			}
		}
	}
	return 0;
}