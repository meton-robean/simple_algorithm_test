#include <stdio.h>
#include <algorithm>
#include <queue>
//#include <functional>
//#include <vector>
using namespace std;
//priority_queue<int> Q; //大顶堆
priority_queue< int, vector<int>, greater<int> > Q;//小顶堆

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(Q.empty()==false){Q.pop();}
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        int weight=0;
        while(Q.size()>1)
        {
            int a=Q.top();
            Q.pop();
            int b=Q.top();
            Q.pop();
            weight+=a+b;
            Q.push(a+b); //Q.push(weigth)
        }
        printf("%d\n",weight);
    }
    return 0;
}