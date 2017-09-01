#include <stdio.h>
int main()
{
	int n;
	int tmp;
	int score_need_count;
	//int score_need_count;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int buf[101]={0};
		for(int i=0;i<n;i++)
		{
			//int tmp;
			scanf("%d",&tmp);
			buf[tmp]++;
		}
		//int score_need_count;
		scanf("%d",&score_need_count);
		printf("count is: \n%d\n",buf[score_need_count]);
	}
	return 0;
}