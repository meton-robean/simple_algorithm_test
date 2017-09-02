#include <stdio.h>
#include <string.h>


int main()
{
    char m_buf[50];
    int m,n;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0) break;
        scanf("%s%d",m_buf,&n);
        int len=strlen(m_buf);
        long tmp=0; //注意，这里tmp要初始化为0
        int weight=1;
        for(int i=len-1;i>=0;i--)
        {
            int x;
            if(m_buf[i]>='0' && m_buf[i]<='9')
            {
                x=m_buf[i]-'0';
            }
            else if(m_buf[i]>='a' && m_buf[i]<='z')
            {
                x=m_buf[i]-'a'+10;
            }
            else if(m_buf[i]>='A' && m_buf[i]<='Z')
            {

            }else{
                return 0;
            }
            tmp+=x*weight;
            weight=weight*m;
        }

        char ans[50];
        int size=0;
        do{
            int x=tmp%n;
            ans[size++]=(x<10)? x+'0':x-10+'A';
            tmp/=n;
        }while(tmp!=0);
        for(int i=size-1;i>=0;i--)//注意，这里是size-1
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
