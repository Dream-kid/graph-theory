//https://uva.onlinejudge.org/external/16/1658.pdf
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 100000000000000
struct node
{
    ll u, v, cap, cost;
    node(ll u1, ll v1, ll cap1, ll cost1)
    {
        u= u1, v = v1, cap = cap1, cost = cost1;
    }
};
vector <node> e;
vector <ll> adj[3010];
ll dis[3010], par[3010];
bool vis[3010];
void add_node(ll u, ll v, ll cap, ll cost)
{
    node e1 = node(u,v,cap,cost);
    node e2 = node(v,u,0,-cost);
    adj[u].push_back (e.size());
    e.push_back(e1);
    adj[v].push_back (e.size());
    e.push_back (e2);
}
bool spfa(ll s, ll t, ll n)
{
    queue <ll> q;
    for (ll i = 0; i < 3001; i++)
    {
        par[i] = -1;
        dis[i] = inf;
        vis[i] = false;
    }

    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while(q.size())
    {
        ll u = q.front();
        q.pop();
        vis[u] = 1;
        for(ll i=0; i<adj[u].size(); i++)
        {
            ll id = adj[u][i];
            ll to = e[id].v;
            ll temp = dis[u] + e[id].cost;
            if(e[id].cap && dis[to] > temp)
            {
                dis[to] = temp;
                q.push(to);
                vis[to] = 1;
                par[to] = id;
            }
        }
    }
    return (dis[t] != inf);
}
pair <ll,ll> min_cost_max_flow(ll s, ll t, ll n)
{
    ll mincost = 0, maxflow = 0;
    while(spfa(s,t,n))
    {
        ll flow = inf + 1;
        ll id = par[t];
        while(id != -1)
        {
            flow = min(flow, e[id].cap);
            id = par[e[id].u];
        }
        id = par[t];
        while(id != -1)
        {
            e[id].cap -= flow;
            e[id ^ 1].cap += flow;
            id = par[e[id].u];
        }
        mincost += dis[t] * flow;
        maxflow += flow;
    }
    return make_pair (maxflow, mincost);
}

int main()
{
    ll total,cnt;
    while(cin>>total>>cnt)
    {
        for(ll i=2; i<total; i++)
        {
            add_node(i,i+total,1,0);
        }
        add_node(0,1,2,0);
        add_node(1,1+total,2,0);
        add_node(total,2*total,2,0);
        add_node(2*total,2*total+1,2,0);
        for(ll i=1; i<=cnt; i++)
        {
            ll a,b,cost;
            cin>>a>>b>>cost;
            add_node(a+total,b,1,cost);
        }
        cout<<min_cost_max_flow(0,2*total+1,2*total+2).second<<endl;
        e.clear();
        for (int i = 0; i < 3001; i++)
        {
            adj[i].clear();
        }
    }
}
