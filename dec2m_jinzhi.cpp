#include <stdio.h>

using namespace std;

int main()
{
    long long a,b;
    int m;//题目前提 m<10
    while(scanf("%d",&m)!=EOF&&m!=0)
    {
        scanf("%lld%lld",&a,&b);
        long long ans=a+b;
        int buf[50];
        int size=0;

        do{
            buf[size++]=ans%m ;
            ans/=m;
        }while(ans!=0);
        for(int i=size-1;i>=0;i--)
        {
            printf("%d",buf[i]);
        }
        printf("\n");
    }
    return 0;
}