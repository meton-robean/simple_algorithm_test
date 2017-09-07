//拓扑排序检测有向图是否有环
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int indegree[501];
vector<int> edge[501];
queue<int> Q;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
        {
            indegree[i]=0;
            edge[i].clear();
        }
        while(m!=0)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            indegree[b]++;
            m--;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                Q.push(i);
            }
        }
        
        int cnt=0;
        while(Q.empty()!=true)
        {
            int nowP=Q.front();
            Q.pop();
            cnt++;
            for(int j=0;j<edge[nowP].size();j++)
            {
                indegree[edge[nowP][j]]--;
                if( indegree[edge[nowP][j]]==0)
                {
                    Q.push(edge[nowP][j]);
                }
            }

        }
        if(cnt==n)
        {
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
