#include <stdio.h>
#include <math.h>

using namespace std;

bool Is_prime_number(int x)
{
    if(x<=1)
    {
        return false;
    }
    int bound= (int)sqrt(x)+1;
    for(int i=2;i<bound;i++)
    {
        if(x%i==0) return false;

    }
    return true;
}

int main(){
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        printf("%s\n",Is_prime_number(x)?"yes":"no");
    }
    return 0;
}