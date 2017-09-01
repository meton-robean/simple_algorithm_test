#include <stdio.h>
#define ISYEAP(x) x%100!=0&&x%4==0 || x%400==0 ? 1:0


using namespace std;

int cnt=0;
int date_table[5001][13][31];
int day_of_month[13][2]={
	0,0,
	31,31, //1
	28,29,
	31,31, //3
	30,30,
	31,31, //5
	30,30, 
	31,31, //7
	31,31, //8
	30,30,
	31,31, //10
	30,30,
	31,31, //12
};

struct Date
{
	int year;
	int month;
	int day;
	void next_day()
	{
		day++;
		if(day>day_of_month[month][ISYEAP(year)])
		{
			day=1;
			month++;
			if(month>12)
			{
				month=1;
				year++;
			}
		}
	}
};

int ABS(int x)
{
	return x<0?-x:x;
}

int main()
{

	Date date;
	date.day=1;
	date.month=1;
	date.year=0; 
	while(date.year!=5001)//init the matric of YMD
	{
		date_table[date.year][date.month][date.day]=cnt;
		date.next_day();
		cnt++;
	}
	int d1,m1,y1;
	int d2,m2,y2;
	int temp;
	printf("input two date:\n");
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		temp=ABS(date_table[y1][m1][d1]-date_table[y2][m2][d2])+1;
		printf("%d day between two date inputed\n",temp);
	}

	return 0;
}


	/* print day_of_month[]
	for(int i=1;i<13;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d ",day_of_month[i][j]);
		}
		printf("\n");
	}
	*/