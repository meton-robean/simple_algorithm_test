#include <stdio.h>

using namespace std;
//最大公约数是 满足a%c=0 b%c=0的C的最大值 
//欧几里得法求最大公约数
int gcd(int a,int b)
{
    while(b!=0)
    {
        //wrong
        //a=b;
        //b=a%b;
         int t=a;
         a=b;
         b=t%b;
    }
    return a;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
