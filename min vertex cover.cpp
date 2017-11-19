
//https://uva.onlinejudge.org/external/102/10243.pdf
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
vector<ll>v[1010];
ll dp[1010][4];
ll parent[100010];
ll bpm(ll u,ll guard)
{
    if(!v[u].size()) return guard;
    if(dp[u][guard]!=-1) return dp[u][guard];
    ll sum=0;
    flop(0,v[u].size()-1,1)
    {
        ll s=v[u][i];
        if(parent[u]==s) continue;
        parent[s]=u;
        if(guard) sum+=min(bpm(s,0),bpm(s,1));
        else sum+=bpm(s,1);
    }
    return dp[u][guard]=sum+guard;
}
int main()
{
    //input;
    //output;
    ll a,b;
    while(sll(a)==1)
    {
        if(a==0) return 0;
        b=a;
        ll q=0;
        cover(dp,-1);
        while(a--)
        {
            q++;
            ll o;
            sll(o);
            while(o--)
            {
                ll p;
                sll(p);
                v[q].pb(p);
            }
        }
        ll o=bpm(1,1);
        cover(dp,-1);
        cover(parent,0);
        o=min(o,bpm(1,0));
        if(o==0) o++;
        pll(o);
        for(ll i=0; i<=b; i++) v[i].clear();
        cover(dp,-1);
        cover(parent,0);
    }
}
