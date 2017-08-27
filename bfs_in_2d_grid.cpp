//http://www.lightoj.com/volume_showproblem.php?problem=1012
#include<bits/stdc++.h>
using namespace std;
#define inf 1010
typedef long long ll;
ll ara_x[4]= {1,-1,0,0};
ll ara_y[4]= {0,0,1,-1};
ll ara[22][22];
ll t=1;
bool can_go(ll ux,ll uy,ll a,ll b)
{
    if(ux<0||uy<0||ux>=b||uy>=a||ara[ux][uy]==1) return false;
    else  return true;
}
void bfs(ll a,ll b,ll x,ll y)
{
    ll visited[22][22]= {0};
    queue<ll>q;
    q.push(x);
    q.push(y);
    visited[x][y]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        for(ll i=0; i<4; i++)
        {
            ll ux=x+ara_x[i];
            ll uy=y+ara_y[i];
            if(can_go(ux,uy,a,b)==true)
            {
                if(visited[ux][uy]==0)
                {
                    visited[ux][uy]=1;
                    q.push(ux);
                    q.push(uy);
                    ara[ux][uy]=2;
                }
            }
        }
    }
    ll count=0;
    for(ll i=0; i<b; i++)
    {

        for(ll j=0; j<a; j++)
        {

            if(ara[i][j]==2) count++;
        }
    }
    printf("Case %lld: %lld\n",t++,count);
}
int main()
{
    ll e;
    scanf("%lld",&e);
    while(e--)
    {
        ll a,b,I,J;
        memset(ara,0,sizeof(ara));
        scanf("%lld%lld",&a,&b);
        for(ll i=0; i<b; i++)
        {
            for(ll j=0; j<a; j++)
            {
                char p;
                cin>>p;
                if(p=='#') ara[i][j]=1;

                else if(p=='@')
                {
                    I=i;
                    J=j;
                    ara[i][j]=2;
                }
            }
        }
        bfs(a,b,I,J);
    }
}
