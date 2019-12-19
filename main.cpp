#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[4];
        int i,j,flag=0,destx,desty;
        for(i=0;i<4;i++)
        {
            cin>>s[i];
        }
        int x1,y1,x2,y2;
        x1=int(s[0]-'a'+1);
        y1=int(s[1]-'0');
        x2=int(s[2]-'a'+1);
        y2=int(s[3]-'0');
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        int x[8]={2,2,-2,-2,1,-1,1,-1};
        int y[8]={1,-1,1,-1,2,-2,2,-2};
        queue<pair<int,int> > q;
        int vis[9][9];
        int dis[9][9];
        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)
            {
                vis[i][j]=0;
                dis[i][j]=0;
            }
        }
        vis[x1][y1]=1;
        q.push(make_pair(x1,y1));
        while(!q.empty())
        {
            pair<int,int> tmp;
            tmp=q.front();
            q.pop();
            int a=tmp.first;
            int b=tmp.second;
            for(i=0;i<=7;i++)
            {
                destx=a+x[i];
                desty=b+y[i];
                if(vis[destx][desty]==0)
                {
                    vis[destx][desty]=1;
                    dis[destx][desty]=dis[a][b]+1;
                    if(destx==x2&&desty==y2)
                    {
                        flag=1;
                        break;
                    }
                    q.push(make_pair(destx,desty));
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
        {
            cout<<dis[destx][desty]<<endl;
        }
        if(t==0)
            break;
    }
    return 0;
}
