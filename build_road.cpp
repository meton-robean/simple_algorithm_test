//检测连通分量个数
#include <stdio.h>

using namespace std;

#define N 1000
int tree[N];

int find_root(int x)
{
    if(tree[x]==-1) return x;//x 没有上级，返回自己
    else
    {
        int tmp= find_road(tree[x]);
        tree[x]=tmp;   //zip the road
        return tmp;
    }
}

int main()
{
    int m,n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        scanf("%d",&m);
        for(int i=0;i<n;i++)
        {
            tree[i]=-1;
        }
        while(m!=0)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a=find_root(a);
            b=find_root(b);
            if(a!=b)
            {
                tree[a]=b;
            }
            m--;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(tree[i]==-1){
                ans++;
            }
        }
        printf("%d\n",ans-1);
    }
    return 0;
}