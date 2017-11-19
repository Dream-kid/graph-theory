//https://uva.onlinejudge.org/external/8/820.pdf
#include <list>

#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <limits>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <bitset>
#include <numeric>
#include <cassert>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

#define sf scanf
#define pf printf
#define pi 2*acos(0.0)
#define ull unsigned long long
#define all(v) v.begin(),v.end()

#define sii(t) scanf("%d",&t)
#define sll(t) scanf("%lld",&t)
#define sll(t) scanf("%lld",&t)
#define ssll(a,b) scanf("%lld%lld",&a,&b)
#define ssd(a,b) scanf("%lf%lf",&a,&b)
#define sssll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ssslf(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define ssssll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Case(no) printf("Case %lld ",++no)
#define nl puts("")
#define pll(a) printf("%lld\n",a)
#define P(a) printf("%d ",a)
#define PLL(a) printf("%lld ",a)


#define ff first
#define pb push_back
#define mp make_pair
#define se second
#define pb push_back
#define ST(v) sort(all(v))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define cover(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)                       //count one
#define output freopen("out.txt","w",stdout)
#define input freopen("in.txt","r",stdin)
#define un(v) ST(v), (v).earse(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
#define flop(m,n,q)             for(ll i=m;i<=n;i+=q)
////============ CONSTANT ===============////
#define mx  (100010)
#define inf 1000000000000000000
#define eps 1e-9
#define mod1 1000000007
typedef long long ll;
////=====================================////
ll arr[110][110];
ll parent[110];
bool bfs(ll size,ll start,ll end)
{
    queue<ll>q;
    q.push(start);
    bool visited[110]= {0};
    visited[start]=1;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=1; i<=size; i++)
        {
            if(i==u) continue;
            if(visited[i]) continue;
            if(!arr[u][i]) continue;
            q.push(i);
            visited[i]=1;
            parent[i]=u;
        }
    }
    if(visited[end]) return true;
    return false;
}
ll ford_fulkerson(ll size,ll start,ll end)
{
    ll max_flow=0;
    while(bfs(size,start,end))
    {
        ll path_flow=inf;
        for(ll i=end; i!=start; i=parent[i])
        {
            ll u=parent[i];
            path_flow=min(arr[u][i],path_flow);
        }
        for(ll i=end; i!=start; i=parent[i])
        {
            ll u=parent[i];
            arr[u][i]-=path_flow;
            arr[i][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}
int main()
{
    //input;
    ll a,t=0;
    while(sll(a)==1)
    {
        if(a==0) return 0;
        ll b,c,d;
        sssll(b,c,d);
        if(b>c) swap(b,c);
        while(d--)
        {
            ll p,q,cost;
            sssll(p,q,cost);
            if(q==p) continue;
            arr[p][q]+=cost;
            arr[q][p]+=cost;
        }
        pf("Network %lld\nThe bandwidth is %lld.\n\n",++t,ford_fulkerson(a,b,c));
        cover(arr,0);
        cover(parent,0);
    }
}
