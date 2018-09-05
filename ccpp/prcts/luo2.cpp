
#include"cstdio"
#include"queue"
#include"cstring"
using namespace std;
typedef pairs<int,int> P;
int N,M;
char maze[105][105];
int signal[105][105];
int ans=0;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int search(int c,int l)
{
    queue<P>que;
    que.push(P(c,l));
    while(!que.empty())
    {
        c=que.front().first,l=que.front().second;
        if(maze[c][l]=='G')
                return signal[c][l];
        que.pop();
        for(int i=0;i<4;i++)
        {
            int x=c+dx[i];
            int y=l+dy[i];
            if(x<0||y<0||x>=N||y>=M)
                continue;
            if(!signal[x][y]&&maze[x][y]!='#')
            {
                signal[x][y]=signal[c][l]+1;
                que.push(P(x,y));
            }
        }
    }
    return -1;
}
int main()
{
    memset(signal,0,sizeof(signal));
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%s",maze[i]);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
    {
        if(maze[i][j]=='S')
            ans=search(i,j);
    }
    printf("%d\n",ans);
    return 0;
} 
