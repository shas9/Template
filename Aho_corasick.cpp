#include <bits/stdc++.h>
using namespace std;
/***template***/
#define ll                   int
#define ___                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dd                   double
#define scl(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  1e18
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
/***template***/

#define maxn                 5000005
#define maxc                 26
#define num_of_patterns      510
ll endd[num_of_patterns];

struct aho_corasick
{
    ll nextt[maxn][maxc];
    ll cnt[maxn];
    ll backedge[maxn];
    ll sz;
    bool vis[maxn];
    vector<ll>out[maxn];


    aho_corasick()
    {
        clear();
    }
    void clear()
    {
        mstt(backedge,-1);
        mstt(nextt[0],-1);
        mstt(cnt,0);
        mstt(vis,0);
        LOOP(i,maxn)
        {
            out[i].clear();
        }
        sz=0;
    }

    void insert(string &s,ll pos)
    {
        ll v=0;
        LOOP(i,s.size())
        {
            ll id=s[i]-'a';
            if(nextt[v][id]==-1)
            {
                nextt[v][id]=++sz;
                mstt(nextt[sz],-1);
            }
            v=nextt[v][id];
        }
        endd[pos]=v;
    }

    void build_matching_machine()
    {
        deque<ll>q;
        LOOP(i,26)
        {
            if(nextt[0][i]!=-1)
            {
                ll adj=nextt[0][i];
                backedge[adj]=0;
                q.pb(adj);
            }
        }

        while(!q.empty())
        {
            ll src=q.front();
            q.pop_front();
            LOOP(i,26)
            {
                ll adj=nextt[src][i];
                if(adj==-1)continue;
                q.pb(adj);
                ll v=backedge[src];
                while(1)
                {
                    if(nextt[v][i]!=-1)
                    {
                        v=nextt[v][i];
                        break;
                    }
                    if(v==0)break;
                    v=backedge[v];
                }
                backedge[adj]=v;
                out[v].pb(adj);
            }
        }
    }
    void search(string &s)
    {
        ll v=0;
        LOOP(i,s.size())
        {
            ll id=s[i]-'a';
            while(1)
            {
                if(nextt[v][id]!=-1)
                {
                    v=nextt[v][id];
                    break;
                }
                if(v==0)break;
                v=backedge[v];
            }
            cnt[v]++;
        }
    }

    ll dfs(ll src)
    {
        if(vis[src])return cnt[src];


        LOOP(i,out[src].size())
        {
            ll adj=out[src][i];
            cnt[src]+=dfs(adj);
        }

        vis[src]=1;
        return cnt[src];
    }
};

aho_corasick tree;

string patterns[510],text;
ll n;
int main()
{
    ___

    tree.clear();
    cin>>n;
    FOR(i,n)
    {
        cin>>patterns[i];
        tree.insert(patterns[i],i);
    }

    tree.build_matching_machine();

    cin>>text;
    tree.search(text);

    FOR(i,n)
    {
        cout<<tree.dfs(endd[i])<<endl;
    }
    return 0;
}
