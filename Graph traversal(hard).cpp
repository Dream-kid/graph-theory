//https://uva.onlinejudge.org/external/124/12442.pdf
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
#define inf 1000000000000000000
#define eps 1e-9
#define mod1 1000000007
typedef long long ll;
////=====================================////
bool visited[50010];
vector<ll>v[50010];
void bfs(ll a)
{
    stack<ll>st;
    queue<ll>q;
    cover(visited,0);
    for(ll i=1; i<=a; i++)
    {
        if(visited[i]) continue;
        if(!v[i].size()) continue;
        visited[i]=true;
        q.push(i);
        st.push(i);
        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            flop(0,v[u].size()-1,1)
            {
                ll s=v[u][i];
                if(visited[s]) continue;
                q.push(s);
                visited[s]=1;
            }
        }
    }

    vector<ll>v1;
    cover(visited,0);
    while(!st.empty())
    {
        ll i=st.top();
        st.pop();
        if(visited[i]) continue;
        if(!v[i].size()) continue;
        visited[i]=true;
        q.push(i);
        v1.pb(i);
        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            flop(0,v[u].size()-1,1)
            {
                ll s=v[u][i];
                if(visited[s]) continue;
                q.push(s);
                visited[s]=1;
            }
        }
    }
    sort(v1.begin(),v1.end());
    ll max=-1;
    ll o;

    for(ll i1=0; i1<v1.size(); i1++)
    {
        ll i=v1[i1];
     cover(visited,0);
        ll cnt=1;
        visited[i]=true;
        q.push(i);
        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            flop(0,v[u].size()-1,1)
            {
                ll s=v[u][i];
                if(visited[s]) continue;
                cnt++;
                q.push(s);
                visited[s]=1;
            }
        }
        if(cnt>max)
        {
            max=cnt;
            o=v1[i1];
        }
    }
    pll(o);
}
int main()
{
    //input;
    //output;
    ll a,t=0;
    sll(a);
    while(a--)
    {
        ll p,q;
        sll(p);
        q=p;
        while(p--)
        {
            ll s,t;
            ssll(s,t);
            v[s].pb(t);
        }
        Case(t);
        bfs(q);
        for(ll i=0; i<=q; i++) v[i].clear();

    }
}
