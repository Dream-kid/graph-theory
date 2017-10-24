//https://uva.onlinejudge.org/external/105/10557.pdf
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
#define Case(no) printf("Case %lld: ",++no)
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
#define inf 100000000000000
#define eps 1e-9
#define mod 10007
typedef long long ll;
////=====================================////
vector<pair<ll,ll> >v[1000];
bool bfs(ll a,ll b)
{
    if(a==b) return true;
    queue<ll>q;
    q.push(a);
    ll visited[1000]= {0};
    visited[a]=1;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0; i<v[u].size(); i++)
        {
            ll s=v[u][i].ff;
            if(!visited[s])
            {
                visited[s]=1;
                q.push(s);
                if(s==b) return true;
            }
        }
    }
    return false;
}
bool beldmenford(ll a)
{
    ll distance1[1000]= {0};
    ll distance2[1000]= {0};
    flop(0,a,1)
    {
        distance1[i]=inf;
        distance2[i]=inf;
    }
    distance1[1]=-100;
    distance2[1]=-100;
    ll visited[1000]= {0};
    flop(1,a-1,1)
    {
        for(ll j=1; j<=a; j++)
        {
            if(v[j].size())
            {
                for(ll k=0; k<v[j].size(); k++)
                {
                    ll o=v[j][k].ff;
                    ll p=v[j][k].se;
                    if(distance1[o]>distance1[j]+p)
                    {
                        if(distance1[j]+p<0)
                            distance1[o]=distance1[j]+p;
                    }
                    if(distance2[o]>distance2[j]+p)
                        distance2[o]=distance2[j]+p;
                }
            }
        }
    }
    if(distance1[a]!=inf) return true;
    if(distance2[a]==inf) return false;
    for(ll j=1; j<=a; j++)
    {
        if(v[j].size())
        {
            for(ll k=0; k<v[j].size(); k++)
            {
                ll o=v[j][k].ff;
                ll p=v[j][k].se;

                if(!visited[o])
                {
                    visited[o]=1;
                    if(distance1[o]>distance1[j]+p)
                    {
                        if(distance1[j]+p<0)
                        {
                            if(bfs(o,a))return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    //input;
    //output;
    ll a;
    while(sll(a)==1)
    {
        if(a==-1) return 0;
        flop(1,a,1)
        {
            ll p,q;
            ssll(p,q);
            p*=-1;
            while(q--)
            {
                ll m;
                sll(m);
                v[i].pb(mp(m,p));
            }
        }
        if(beldmenford(a)) pf("winnable\n");
        else pf("hopeless\n");
        flop(0,a,1) v[i].clear();
    }
}
