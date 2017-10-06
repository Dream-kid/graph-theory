//https://uva.onlinejudge.org/external/115/11504.pdf
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
#define sssld(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define ssssll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Case(no) printf("Case %lld: ",++no)
#define nl puts("")
#define p(a) printf("%d\n",a)
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
#define mod 10007
typedef long long ll;
////=====================================////
vector<ll>v[100010];
struct node1
{
    ll visited1,visited2;
} node[100010];
ll domino(ll b)
{
    stack<ll>s;
    for(ll i=1; i<=b; i++)
    {
        if(node[i].visited1==0)
        {
            s.push(i);
            queue<ll>q;
            q.push(i);
            node[i].visited1=1;
            while(!q.empty())
            {

                ll u=q.front();
                q.pop();
                if(v[u].size())
                {
                    for(ll j=0; j<v[u].size(); j++)
                    {
                        ll g=v[u][j];
                        if(node[g].visited1==0)
                        {
                            node[g].visited1=1;
                            q.push(g);
                        }
                    }
                }
            }
        }
    }
    ll cnt=0;
    while(!s.empty())
    {

        ll i=s.top();
        //v[i].clear();
        s.pop();
        if(node[i].visited2==0)
        {
            cnt++;
            queue<ll>q;
            q.push(i);
            node[i].visited2=1;
            while(!q.empty())
            {

                ll u=q.front();


                q.pop();
                if(v[u].size())
                {
                    for(ll j=0; j<v[u].size(); j++)
                    {
                        ll g=v[u][j];
                        if(node[g].visited2==0)
                        {

                            node[g].visited2=1;
                            q.push(g);

                        }

                    }
                }


            }
        }
    }
    pll(cnt);

}


int main()
{
   //input;
    ll a;
    sll(a);
    while(a--)
    {
        ll b,c;
        ssll(b,c);
        while(c--)
        {
            ll p,q;
            ssll(p,q);
            v[p].pb(q);
            //v[q].pb(p);

        }
        domino(b);
        flop(0,b,1) v[i].clear();
        cover(node,0);
    }
}
