//http://lightoj.com/volume_showproblem.php?problem=1154
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define inf 100000
struct dinic_flow
{
    struct edge
    {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d)
        {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;
    int INF = 1500000001 ;
    int  s, t, d [ 301 ],ptr[301],q[301 ] ;
    vector < edge > e ;
    vector < int > g [ 301 ] ;
    void add_edge ( int a, int b, int cap )
    {
        edge e1 =edge( a, b, cap, 0 ) ;
        edge e2 =edge( b, a, 0, 0 ) ;
        g[a].push_back((int)e.size());
        e. push_back ( e1 ) ;
        g[b].push_back((int)e.size());
        e. push_back ( e2 ) ;
    }
    bool bfs ( )
    {
        int qh = 0, qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1, sizeof d ) ;
        d [ s ] = 0 ;
        while(qh<qt&&d[t] == - 1 )
        {
            int v = q [ qh ++ ] ;
            for (size_t i=0; i<g[v].size(); ++i)
            {
                int id=g[v][i], to=e[id].b ;
                if(d[to]==-1 && e[id ].flow < e [ id ] . cap )
                {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }
    int dfs ( int v, int flow )
    {
        if ( ! flow )
            return 0 ;
        if ( v == t )
            return flow ;
        for(; ptr[v]<(int)g[v].size(); ++ptr [ v ] )
        {
            int id = g [v][ptr[v]], to = e [ id ] . b ;
            if(d[to]!=d[v] + 1 )
                continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap
                                         - e [ id ] . flow ) ) ;
            if ( pushed )
            {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }
    int dinic ( )
    {
        int flow = 0 ;
        for ( ;; )
        {
            if ( !bfs () )
                break ;
            memset ( ptr, 0, sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) )
            {
                flow += pushed ;
                if(pushed == 0)
                    break;
            }
        }
        return flow ;
    }
    void dinic_maxflow(  int _s, int _t )
    {
        s = _s;
        t = _t;
    }
};
struct node
{
    double x,y,num,cap;
} arr[210];
int main()
{
    ll ts;
    cin>>ts;
    for(ll t=1; t<=ts; t++)
    {
        ll total;
        double dis;
        cin>>total>>dis;
        dis*=dis;
        ll sum=0;
        ll src=2*total+1;
        for(ll i=1; i<=total; i++)
        {
            cin>>arr[i].x>>arr[i].y>>arr[i].num>>arr[i].cap;
            sum+=arr[i].num;
        }
        bool mark=0;
        cout<<"Case "<<t<<":";
        for(ll i=1; i<=total; i++)
        {
            dinic_flow g;
            for(ll j=1; j<=total; j++)
            {
                g.add_edge(src,j,arr[j].num);
                g.add_edge(j,j+total,arr[j].cap);
                for(ll k=j+1; k<=total; k++)
                {
                    double temp=(arr[k].x-arr[j].x)*(arr[k].x-arr[j].x)+(arr[k].y-arr[j].y)*(arr[k].y-arr[j].y);
                    if(temp<=dis)
                    {
                        g.add_edge(j+total,k,inf);
                        g.add_edge(k+total,j,inf);
                    }
                }
            }
            g.dinic_maxflow(src,i);
            ll temp=g.dinic();
            if(temp==sum)
            {
                mark=1;
                cout<<" "<<i-1;
            }
        }
        if(!mark)
            cout<<" -1"<<endl;
        else
            cout<<endl;
    }
}
