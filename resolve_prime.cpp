//分解素因数
#include <stdio.h>

using namespace std;

bool mark[100001];
int prime[100001];
int prime_size; //global var

void init()
{
    for(int i=1;i<=100001;i++)
    {
        mark[i]=false;
    }
    prime_size=0;
    for(int i=2;i<=100001;i++)
    {
        if(mark[i]==true)
        {
            continue;
        }
        prime[prime_size++]=i;
        mark[i]=false;
        for(int j=2*i;j<=100001;j+=i)
        {
            mark[j]=true;
        }
    }
}


int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int prime_yinshu[50];
        int yinshu_count=0;
        int prime_mi[50];
        for(int i=0;i<prime_size;i++)
        {
            if(n%prime[i]==0)
            {
                prime_yinshu[yinshu_count]=prime[i];
                //prime_yinshu_count=0;
                prime_mi[yinshu_count]=0;
                while(n%prime[i]==0)
                {
                    prime_mi[yinshu_count]++;
                    n/=prime[i];
                }
                yinshu_count++;
                if(n==1) break;
            }
        }
        int ans=0;
        for(int i=0;i<yinshu_count;i++)
        {
            ans+=prime_mi[i];
            
        }
        printf("%d\n",ans);
    }

    return 0;
}
