//https://uva.onlinejudge.org/external/105/10557.pdf
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 100000
#define inf  1000000007

vector<pair<ll,ll> >v[1000];
bool vis[1000];
ll dis[1000];
bool bfs(ll u,ll total)
{
    vis[u]=1;
    if(u==total)
        return 1;
    queue<ll>q;
    q.push(u);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0; i<v[u].size(); i++)
        {
            ll s=v[u][i].first;
            if(vis[s])
                continue;
            vis[s]=1;
            if(s==total)
                return 1;
            q.push(s);
        }
    }
    return 0;
}

bool bellmanford(ll total)
{
    memset(vis,0,sizeof vis);
    for(ll i=1; i<=total; i++)
        dis[i]=inf;
    dis[1]=-100;
    for(ll i=1; i<=total; i++)
    {
        for(ll j=0; j<v[i].size(); j++)
        {
            ll s=v[i][j].first;
            ll val=v[i][j].second;
            ll temp=dis[i] + val;
            if(temp<dis[s]&&temp<=-1)
                dis[s]=temp;
        }
    }
    if(dis[total]!=inf)
        return 1;

    for(ll i=1; i<=total; i++)
    {
        for(ll j=0; j<v[i].size(); j++)
        {
            ll s=v[i][j].first;
            ll val=v[i][j].second;
            ll temp=dis[i] + val;
            if(temp<dis[s]&&temp<=-1)
            {
                if(bfs(s,total))
                    return 1;
            }
        }
    }
    return 0;

}

int main()
{
    //freopen("out.txt","w",stdout);
    ll total;
    while(cin>>total)
    {
        if(total==-1)
            return 0;
        for(ll i=1; i<=total; i++)
        {
            ll val,cnt;
            cin>>val>>cnt;
            val*=-1;
            while(cnt--)
            {
                ll temp;
                cin>>temp;
                v[i].push_back({temp,val});
            }
        }
        if(bellmanford(total))
            cout<<"winnable"<<endl;
        else
            cout<<"hopeless"<<endl;
        for(ll i=1; i<=total; i++)
            v[i].clear();
    }

}

