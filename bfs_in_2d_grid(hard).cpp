//http://www.lightoj.com/volume_showproblem.php?problem=1066
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
 
#define sc scanf
#define pf printf
#define pi 2*acos(0.0)
#define ull unsigned long long
#define all(v) v.begin(),v.end()
 
#define sii(t) scanf("%d",&t)
#define sll(t) scanf("%lld",&t)
#define ssii(a,b) scanf("%d%d",&a,&b)
#define ssll(a,b) scanf("%lld%lld",&a,&b)
#define Case(no) printf("Case %lld: ",++no)
#define nl puts("")
#define p(a) printf("%d\n",a)
#define pll(a) printf("%lld\n",a)
#define P(a) printf("%d ",a)
#define PLL(a) printf("%lld ",a)
 
 
#define ff first
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
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define un(v) ST(v), (v).earse(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
#define flop(m,n,q)             for(ll i=m;i<n;i+=q)
////============ CONSTANT ===============////
#define mx  (100010)
#define inf 1000000000000000000
#define eps 1e-9
#define mod 10007
////=====================================////
typedef long long ll;
char ara[20][20];
ll k;
ll ara_x[4]= {1,-1,0,0};
ll ara_y[4]= {0,0,1,-1};
bool can_go(ll x,ll y,char C,ll b)
{
    if(x<=0||y<=0||x>b||y>b) return false;
    if(ara[x][y]=='.'||ara[x][y]==C)
    {
        if(ara[x][y]==C)
        {
            k++;
            ara[x][y]='.';
        }
        return true;
    }
    return false;
}
ll bfs_in_2d_grid(ll x,ll y,ll b,ll count)
{
    ll visited[20][20]= {0};
    ll distance[20][20]= {0};
    char H='B',C;
    visited[x][y]=1;
    distance[x][y]=0;
    ara[x][y]='.';
    queue<ll>q;
    q.push(x);
    q.push(y);
    ll X,Y,g;
    ll count1=0;
read:
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        for(ll i=0; i<4; i++)
        {
            X=x+ara_x[i];
            Y=y+ara_y[i];
            C=H+k;
            if(k==count)
            {
                while(!q.empty()) q.pop();
                return count1;
            }
            g=k;
            if(can_go(X,Y,C,b))
            {
                if(visited[X][Y]==0)
                {
                    if(k!=g)
                    {
                        distance[X][Y]=distance[x][y]+1;
                        count1+=distance[X][Y];
                        cover(visited,0);
                        cover(distance,0);
                        while(!q.empty())q.pop();
                        q.push(X);
                        q.push(Y);
                        distance[X][Y]=0;
                        visited[X][Y]=1;
                        goto read;
                    }
                    q.push(X);
                    q.push(Y);
 
                    distance[X][Y]=distance[x][y]+1;
                    visited[X][Y]=1;
                }
            }
        }
    }
    return inf;
}
int main()
{
    ll a,t=0;
    sll(a);
    while(a--)
    {
        Case(t);
        ll b,c,p,q,count=-1;
        sll(b);
        k=0;
        for(ll i=1; i<=b; i++)
        {
            for(ll j=1; j<=b; j++)
            {
                cin>>ara[i][j];
                if(ara[i][j]=='A')
                {
                    p=i,q=j;
                }
                if(isalpha(ara[i][j])) count++;
            }
        }
        ll o;
        o=bfs_in_2d_grid(p,q,b,count);
        if(o==inf)
            pf("Impossible\n");
        else
            pll(o);
        cover(ara,0);
    }
}
 
