//递归回溯枚举 ，DFS解决素数环问题
#include <stdio.h>
#include <string.h>
using namespace std;

int ans[22];
bool hash[22];
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool judge(int x)
{
    for (int i = 0; i < 13; i++)
    {
        if(prime[i]==x) return true;
    }
    return false;
}

void DFS(int num)
{
    if(num>1)
    {
        if(judge(ans[num]+ans[num-1])==false) return;
    }
    if(num==n){
        if(judge(ans[1]+ans[n])==false) return;
        for(int i=1;i<=n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
        return;//搜索下一组符合条件的解；
    }
    for(int i=2;i<=n;i++)
    {
        if(hash[i]==false)
        {
            hash[i]=true;
            ans[num+1]=i;
            DFS(num+1);
            hash[i]=false;
        }
    }

}

int main()
{
    //int case=0;
    while (scanf("%d",&n)!=EOF)
    {
        //case ++;
        for (int i = 0; i <22; i++)
        {
            hash[i]=false;
        }
        ans[1]=1;
        hash[1]=true;
       // printf("Case %d:\n",case);
        DFS(1);
        printf("\n");
    }
    return 0;
}