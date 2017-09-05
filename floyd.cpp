//FLOYD法其实是动态规划思想，要求两点之间最短，就必须允许中间经过其他点。
#include <stdio.h>
#define inf 99999999 //保证两个inf相加不会超过int的范围
using namespace std;

int grap[101][101];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) //init
        {
            for(int j=1;j<=n;j++)
            {
                grap[i][j]=inf;
            }
            grap[i][i]=0;
        }
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            grap[a][b]=grap[b][a]=c;

        }

        for(int k=1;k<=n;k++) //Floyd
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(grap[i][j]>grap[i][k]+grap[k][j])
                    {
                        grap[i][j]>grap[i][k]+grap[k][j];
                    }
                }
            }
        }
        printf("%d\n",grap[1][n]);

    }
    return 0;
}