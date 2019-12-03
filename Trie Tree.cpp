#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 50005

using namespace std;

ll nextt[maxn][27];
ll endmark[maxn];
ll sz;
char str[maxn];
void cle()
{
    memset(nextt,-1,sizeof nextt);
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;
   }
    sz=0;
}
void insert()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'a';
        if(nextt[v][id]==-1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
    }
    endmark[v]++;
}
ll search()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1;i++)
    {
        ll id=str[i]-'a';
        if(nextt[v][id]==-1)
        {
            return 0;
        }
        v=nextt[v][id];
    }
    return endmark[v];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

    }


}
