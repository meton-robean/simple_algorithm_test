#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Student
{
	char name[100];
	int age;
	int score;
}student[100];

bool compare(Student s1,Student s2)
{
	if(s1.score!=s2.score) return s1.score<s2.score;
	int compare_flag=strcmp(s1.name,s2.name);
	if(compare_flag!=0) return s1.name<s2.name;
	else return s1.age<s2.age;
}

int main()
{
	int n;
	printf("input the n of the int \n");
	while(scanf("%d",&n)!=EOF)// must add & ; &n
	{
		printf("input the number!!\n");		
		for(int i=0;i<n;i++)
		{
			scanf("%s%d%d",student[i].name,&student[i].age,&student[i].score);
		}
		sort(student,student+n,compare);
		for(int i=0;i<n;i++)
		{
			printf("%s %d %d \n", student[i].name,student[i].age,student[i].score);
		}
	}

	return 0;
}