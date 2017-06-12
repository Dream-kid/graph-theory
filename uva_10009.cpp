# shorthest path
#include<bits/stdc++.h>
#include <string>

using namespace std;
typedef long long lli;
vector<lli>v[10000];
vector<lli>v1;

queue<lli>q;




void bfs1(lli start,lli end1)
{
    while(!q.empty()) q.pop();
    if(start==end1) return;
    lli distance1[1000]= {0};
    lli visited[1000]= {0};


    visited[start]=1;
    q.push(start);
    lli u=q.front();
    while(!q.empty())
    {
        u=q.front();

        q.pop();


        for(lli i=0; i<v[u].size(); i++)
        {
            lli s=v[u][i];
            if(visited[s]==0)
            {

                distance1[s]=distance1[u]+1;
                visited[s]=1;
                q.push(s);


                if(end1==s)
                {


                    v1.push_back(u);

                    bfs1(start,u);

                    return;
                }


            }



        }


    }
    return;




}

int main()
{
//   freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout);
    lli a;

    map<char,lli>m;
    set<lli>myset;
    map<lli,char>m1;
    m['A']=1;
    m['B']=2;
    m['C']=3;
    m['D']=4;
    m['E']=5;
    m['F']=6;
    m['G']=7;
    m['H']=8;
    m['I']=9;
    m['J']=10;
    m['K']=11;
    m['L']=12;
    m['M']=13;
    m['N']=14;
    m['O']=15;
    m['P']=16;
    m['Q']=17;
    m['R']=18;
    m['S']=19;
    m['T']=20;
    m['U']=21;
    m['V']=22;
    m['W']=23;
    m['X']=24;
    m['Y']=25;
    m['Z']=26;
    m1[1]='A';
    m1[2]='B';
    m1[3]='C';
    m1[4]='D';
    m1[5]='E';
    m1[6]='F';
    m1[7]='G';
    m1[8]='H';
    m1[9]='I';
    m1[10]='J';
    m1[11]='K';
    m1[12]='L';
    m1[13]='M';
    m1[14]='N';
    m1[15]='O';
    m1[16]='P';
    m1[17]='Q';
    m1[18]='R';
    m1[19]='S';
    m1[20]='T';
    m1[21]='U';
    m1[22]='V';
    m1[23]='W';
    m1[24]='X';
    m1[25]='Y';
    m1[26]='Z';

    cin>>a;
    lli   t=1;
    while(a--)
    {
        string s;
        if(t!=1) cout<<endl;
        t++;
        string t;
        lli n,h,p,q1,i;
        cin>>p>>q1;

        for(i=1; i<=p; i++)
        {

            cin>>s>>t;
            n=m[s[0]];
            h=m[t[0]];
            myset.insert(n);
            myset.insert(h);
            v[h].push_back(n);
            v[n].push_back(h);


        }


        for(i=1; i<=q1; i++)
        {


            cin>>s>>t;

            n=m[s[0]];
            h=m[t[0]];
            v1.push_back(h);

            bfs1(n,h);

            reverse(v1.begin(),v1.end());

            for(lli k=0; k<v1.size(); k++)
            {

                cout<<m1[v1[k]];
            }
            cout<<endl;
            v1.clear();



        }

        for(set<lli>::iterator it=myset.begin(); it!=myset.end(); it++)
        {

            v[*it].clear();




        }
        myset.clear();


    }



}
