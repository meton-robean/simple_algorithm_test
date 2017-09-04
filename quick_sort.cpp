//quick sort思想：挖坑填坑+分治法
//http://blog.csdn.net/morewindows/article/details/6684558
#include <stdio.h>

using namespace std;

int partition(int s[],int low ,int high)
{
    int i=low;
    int j=high;
    int x=s[low];//choose the base number
    while(i<j)
    {
        while(i<j&&s[j]>=x)//从右到左找小于X的数去填前面的坑
        {
            j--;
        }
        if(i<j)//找到那个小于X的数
        {
            s[i]=s[j];
            i++;
        }
        while(i<j&&s[i]<x)//从左到右找大于X的数去填后面的坑
        {
            i++;
        }
        if(i<j)//找到那个大于X的数
        {
            s[j]=s[i];
            j--;
        }

    }
    s[i]=x;
    return i;
}

void quick_sort(int s[],int low ,int high)
{
    if(low<high)
    {
        int i=partition(s,low,high);
        quick_sort(s,low,i-1);
        quick_sort(s,i+1,high);
    }
}

int main()
{
    int s[50];
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }

        quick_sort(s,0,n-1);
        for(int i=0;i<n;i++)
        {
            printf("%d ",s[i]);
        }
        printf("\n");
    }

    return 0;
}