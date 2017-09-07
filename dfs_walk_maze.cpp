#include <stdio.h>

using namespace std;
char maze[8][8];
int n,m,t;
bool success;
int go[][2]={1,0,-1,0,0,1,0,-1};

void dfs(x,y,time)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(maze[nx][ny]=='X') continue;
        if(nx<1 || nx>n || ny<1 ||ny>m) continue;
        if (maze[nx][ny]=='D')
        {
            if (time+1==t)
            {
                success=true;
                return;
            }
            else
            {
                continue;
            }
        }
        maze[nx][ny]='X';
        dfs(nx,ny,time+1);
        maze[nx][ny]='.';
        if(success) return;
    }
}
int main()
{
    
    return 0;
}