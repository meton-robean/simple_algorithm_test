//修路，要求路最短--》求最小生成树
#include <stdio.h>
#include <algorithm>

using namespace std;
int tree[50];
struct edge{
    int a;
    int b;
    int cost;
    bool operator <(const edge & edge2) const
    {
        return cost<edge2.cost;
    }
}edge[1000];

int find_root(int x) //找到集合的根节点
{
    if(tree[x]==-1) return x;
    else {
        int tmp=find_root(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=1;i<=n*(n-1)/2;i++)
        {
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        sort(edge+1,edge+1+n*(n-1)/2);
        for(int i=0;i<n;i++)
        {
            tree[i]=-1;
        }
        int ans=0;
        for(int i=1;i<=n*(n-1)/2;i++)
        {
            int a=find_root(edge[i].a);
            int b=find_root(edge[i].b);
            if(a!=b)
            {
                tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}