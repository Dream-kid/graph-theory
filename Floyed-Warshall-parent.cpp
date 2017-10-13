//https://uva.onlinejudge.org/external/3/341.pdf
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
#define mod 10007
typedef long long ll;
////=====================================////
ll arr[410][410];
ll arr1[410][410];
bool mark=false;
void print_path(ll i,ll j)
{
    if(i!=j) print_path(i,arr1[i][j]);
    if(mark)pf(" ");
    mark=true;
    pf("%lld",j);
}
int main()
{
    //input;
    //output;
    ll a,t=0;
    while(sll(a)==1)
    {
        ll a1=a;
        mark=false;
        if(a==0) return 0;
        flop(1,a,1)
        {
            for(ll j=1; j<=a; j++)
            {
                if(i!=j)arr[i][j]=inf;
                arr1[i][j]=inf;
            }
        }
        ll i1=1;
        ll p,q;
        ll o;
        while(a--)
        {
            sll(o);
            while(o--)
            {
                ssll(p,q);
                arr[i1][p]=q;
            }
            i1++;
        }
        ssll(p,q);
        a=a1;
        flop(1,a,1)
        {
            for(ll j=1; j<=a; j++)
            {
                if(arr[i][j]!=inf)arr1[i][j]=i;
            }
        }
        for(ll k=1; k<=a; k++)
        {
            for(ll i=1; i<=a; i++)
            {
                for(ll j=1; j<=a; j++)
                {
                    if(arr[i][j]>arr[i][k]+arr[k][j])
                    {
                        arr[i][j]=arr[i][k]+arr[k][j];
                        arr1[i][j]=arr1[k][j];
                    }
                }
            }
        }
        Case(t);
        pf("Path = ");
        print_path(p,q);
        pf("; %lld second delay\n",arr[p][q]);
    }
}
