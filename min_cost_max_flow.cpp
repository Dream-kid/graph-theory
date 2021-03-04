//https://lightoj.com/problem/gift-packing
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define inf 100000000
const int maxm=6000;
const int maxn=6000;
struct Node
{
    int to;
    int capa;
    int cost;
    int next;
} edge[maxm];
int source,sink;
int cnt;
int head[maxn];
bool vis[maxn];
int num[maxn];
int dep[maxn];
int pre[maxn];
int rec[maxn];
int dis[maxn];
void init()
{
    memset(head,-1,sizeof(head));
    memset(pre,-1,sizeof(pre));
    memset(rec,-1,sizeof(rec));
    cnt=0;
    return;
}
void add(int u,int v,int capa,int cost)
{
    edge[cnt].to=v;
    edge[cnt].capa=capa;
    edge[cnt].cost=cost;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].to=u;
    edge[cnt].capa=0;
    edge[cnt].cost=-cost;
    edge[cnt].next=head[v];
    head[v]=cnt++;
    return;
}
bool spfa()
{
    queue<int> que;
    que.push(source);
    for(ll i=0;i<6000;i++)dis[i]=inf;
    //memset(dis,inf,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[source]=0;
    vis[source]=true;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        vis[node]=false;
        for(int i=head[node]; ~i; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].capa>0&&dis[v]>dis[node]+edge[i].cost)
            {
                dis[v]=dis[node]+edge[i].cost;
                rec[v]=i;
                pre[v]=node;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return dis[sink]!=inf;
}
int mcmf()
{
    int maxflow=0;
    int mincost=0;
    while(spfa())
    {
        int node=sink;
        int flow=inf;
        while(node!=source)
        {
            flow=min(flow,edge[rec[node]].capa);
            node=pre[node];
        }
        node=sink;
        while(node!=source)
        {
            mincost+=flow*edge[rec[node]].cost;
            edge[rec[node]].capa-=flow;
            edge[rec[node]^1].capa+=flow;
            node=pre[node];
        }
    }
    return -mincost;
}
int main()
{
    ll ts;

    cin>>ts;
    for(ll t=1; t<=ts; t++)
    {
        ll total;
        init();
        cin>>total;
        for(ll i=1; i<=total; i++)
        {
            for(ll j=1; j<=total; j++)
            {
                ll val;
                cin>>val;
                add(i,j+total,1,-val);
            }
        }
        ll src=5600;
        ll des=5700;
        source =src;
        sink=des;
        for(ll i=1; i<=total; i++)
        {
            add(src,i,1,0);
            add(i+total,des,1,0);
        }
        cout<<"Case "<<t<<": "<<mcmf()<<endl;

    }

}
