//segment tree max in range
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const lli inf = -10;

lli ara[10000];
lli tree[10005*4];

void build(lli node,lli b,lli e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return ;
    }
    build(node*2,b,(b+e)/2);
    build(node*2+1,(b+e)/2+1,e);
    tree[node]=max(tree[node*2],tree[node*2+1]);
    return;
}

lli query(lli node,lli b,lli e,lli i,lli j)
{
    if(i>e || j<b) return inf;
    if(i<=b && j>=e ) return tree[node];
    return max(query(node*2,b,(b+e)/2,i,j),query(node*2+1,(b+e)/2+1,e,i,j));
}

int main()
{
    lli n;
    cin>>n;
    for(lli i=1; i<=n; i++)
        cin>>ara[i];
    build(1,1,n);
    lli q;
    cin>>q;
    while(q--)
    {
        lli i,j;
        cin>>i>>j;
        cout<<query(1,1,n,i,j)<<endl;
    }
    
}
