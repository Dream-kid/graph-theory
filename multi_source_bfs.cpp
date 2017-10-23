//http://www.lightoj.com/volume_showproblem.php?problem=1337
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
struct node1
{
    ll arr,adj_list,visited_fire,visited_joe;
} node[210][210];
ll arr_x[4]= {0,0,1,-1};
ll arr_y[4]= {1,-1,0,0};
queue<pair<ll,ll> >q1;
bool can_go_fire(ll a,ll b,ll x,ll y)
{
    if(x<=0||y<=0||x>a||y>b) return false;
    return true;
}
ll can_go_joe(ll a,ll b,ll x,ll y)
{
    if(x<=0||y<=0||x>a||y>b) return 2;
    if(node[y][x].arr==node[y][x].adj_list||node[y][x].arr-1==node[y][x].adj_list) return 0;
    return 1;
}
void bfs_fire(ll a,ll b)
{
    ll x,y,ux,uy;
    while(!q1.empty())
    {
        ll x=q1.front().ff;
        ll y=q1.front().se;
        q1.pop();
        flop(0,3,1)
        {
            ux=x+arr_x[i];
            uy=y+arr_y[i];
            if(!node[uy][ux].visited_fire)
            {
                node[uy][ux].visited_fire=1;
                if(can_go_fire(a,b,ux,uy))
                {
                    q1.push(mp(ux,uy));
                    node[uy][ux].adj_list=node[y][x].adj_list+1;
                }
            }
        }
    }
}
ll bfs_joe(ll a,ll b,ll x,ll y)
{
    ll ux,uy;
    q1.push(mp(x,y));
    while(!q1.empty())
    {
        ll x=q1.front().ff;
        ll y=q1.front().se;
        q1.pop();
        flop(0,3,1)
        {
            ux=x+arr_x[i];
            uy=y+arr_y[i];
            if(!node[uy][ux].visited_joe)
            {
                node[uy][ux].visited_joe=1;
                node[uy][ux].arr=node[y][x].arr+1;
                ll k=can_go_joe(a,b,ux,uy);
                if(k)
                {
                    if(k==2)
                    {
                        while(!q1.empty()) q1.pop();
                        pll(node[uy][ux].arr);
                        return 1;
                    }
                    q1.push(mp(ux,uy));
                }
            }
        }
    }
    return 0;
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
        ssll(p,q);
        char o;
        ll x,y;
        flop(1,p,1)
        {
            for(ll j=1; j<=q; j++)
            {
                cin>>o;
                node[i][j].adj_list=inf;
                if(o=='J')
                {
                    x=j;
                    y=i;
                    node[i][j].visited_joe=1;
                }
                else if(o=='F')
                {
                    q1.push(mp(j,i));
                    node[i][j].adj_list=0;
                    node[i][j].visited_fire=1;
                }
                else if(o=='#')
                {
                    node[i][j].visited_fire=1;
                    node[i][j].visited_joe=1;
                }
            }
        }
        Case(t);
        bfs_fire(q,p);
        if(!bfs_joe(q,p,x,y)) pf("IMPOSSIBLE\n");
        cover(node,0);
    }
}
