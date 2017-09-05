#include <stdio.h>
#include <vector>
#define inf 99999999
using namespace std;

struct edge{
    int posite_vex;
    int weight;
};

vector<edge> Vex[101];
bool mark[101];
int dist[101];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) Vex[i].clear();
        int a,b,weight;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&weight);
            edge tmp_edge;
            tmp_edge.weight=weight;
            tmp_edge.posite_vex=b;
            Vex[a].push_back(tmp_edge);
            tmp_edge.posite_vex=a;
            Vex[b].push_back(tmp_edge);
        }
        for(int i=1;i<=n;i++)
        {
            dist[i]=inf;
            mark[i]=false;
        }
        dist[1]=0;
        mark[1]=true;
        int newP=1;
        //Distraj单源最短路径算法
        for(int k=1;k<n;k++) //大循环 n-1次
        {
            for(int i=0;i<Vex[newP].size();i++)//检查与当前顶点相连的边
            {
                int pv=Vex[newP][i].posite_vex;
                int w=Vex[newP][i].weight;
                if(dist[pv]==inf||dist[pv]>dist[newP]+w)
                {
                    dist[pv]=dist[newP]+w;
                }
            }

            int min=inf;
            for(int j=1;j<=n;j++)
            {
                if(dist[j]==inf) continue;
                if(mark[j]==true) continue;
                if(dist[j]<min)
                {
                    min=dist[j];
                    newP=j;
                }
            }
            mark[newP]=true;
        }

        printf("%d\n",dist[n]);
    }
    return 0;
}