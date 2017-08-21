#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<queue>
using namespace std;
typedef long long ll;
ll ara[1010][1010];
ll x_ara[4]= {1,-1,0,0};
ll y_ara[4]= {0,0,1,-1};
ll distance1[1010][1010];
ll visited[1010][1010];
bool can_go(ll a,ll b,ll d,ll e)
{
    if(a<0||b<0||a>=d||b>=e||ara[a][b]==1) return false;
    return true;
}
void(bfs(ll a,ll b,ll d,ll e))
{
    ll  ux,uy;
    visited[a][b]=1;
    queue<ll>q;
    q.push(a);
    q.push(b);
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        b=q.front();
        q.pop();
        for(ll i=0; i<4; i++)
        {
            ux=a+x_ara[i];
            uy=b+y_ara[i];

            if(can_go(ux,uy,d,e))
            {
                if(visited[ux][uy]==0)
                {
                    visited[ux][uy]=1;
                    q.push(ux);
                    q.push(uy);
                    distance1[ux][uy]=distance1[a][b]+1;
                }
            }
        }

    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a,b,c;
    while(scanf("%lld%lld",&a,&b))
    {
        if(a==0&&b==0) return 0;
        scanf("%lld",&c);
        while(c--)
        {
            ll p,q,s;
            scanf("%lld%lld",&p,&q);
            while(q--)
            {
                scanf("%lld",&s);
                ara[p][s]=1;

            }
        }
        ll m,n,o,p;
        scanf("%lld%lld%lld%lld",&m,&n,&o,&p);
        bfs(m,n,a,b);
        printf("%lld\n",distance1[o][p]);
        memset(distance1,0,sizeof(distance1));
        memset(visited,0,sizeof(visited));
        memset(ara,0,sizeof(ara));
    }
}
