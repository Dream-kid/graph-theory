#include<bits/stdc++.h>
using namespace std;
#define inf 100010
typedef int ll;
ll vis[250];
ll dis[250];
ll res[250][250];
ll ac;
ll p[250];
ll start=0;
ll sink=11;
ll f;
void func(ll v,ll minedge)
{
    if(v==start)
    {
        f=minedge;
        return;
    }
    else if(p[v]!=-1)
    {
        func(p[v],min(minedge,res[p[v]][v]));
        res[p[v]][v]-=f;
        res[v][p[v]]+=f;
    }
    return;
}
ll max_flow()
{
    ll mf=0;
    while(1)
    {
        f=0;
        for(ll i=0; i<=100; i++)
            dis[i]=inf;
        dis[start]=0;
        queue<ll>q;
        q.push(start);
        for(ll i=0; i<=100; i++)
        {
            p[i]=-1;
        }
        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            if(u==sink)
                break;
            for(ll i=0; i<=100; i++)
            {
                if(res[u][i]>0&&dis[i]==inf)
                {
                    dis[i]=dis[u]+1;
                    q.push(i);
                    p[i]=u;
                }

            }
        }
        func(sink,inf);
        if(f==0)
            break;
        mf+=f;
    }
    return mf;
}
int main()
{
    char p;
    while(cin>>p)
    {
        memset(res,0,sizeof res);
        ll src=0,sink=11;
        for(ll i=1; i<=10; i++)
            res[i][sink]=1;
        ll cnt=0;
        while(1)
        {

            ll val;
            cin>>val;
            cnt+=val;
            res[0][p]=val;
            string str;
            cin>>str;
            for(ll i=0; i<str.size()-1; i++)
            {

                res[p][str[i]-'0'+1]=1;
            }
            getchar();
            p=getchar();
            if(!isalpha(p))
            {
                break;
            }
        }
        ll temp1=max_flow();
        if(temp1!=cnt)
            cout<<"!"<<endl;
        else
        {
            map<ll,char>m;
            for(ll i='A'; i<='Z'; i++)
            {
                for(ll j=1; j<=10; j++)
                {
                    if(res[j][i]==1)
                        m[j]=i;
                }
            }
            for(ll i=1; i<=10; i++)
            {
                if(m[i]==0)
                    cout<<'_';
                else
                    cout<<m[i];
            }
            cout<<endl;
        }
    }
}
