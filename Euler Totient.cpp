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


using namespace std;

int phi[10000001]={0};


void computeTotient(int n)
{
    for (int i=1; i<=n; i++)
        phi[i] = i;
    for (int p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;

            for (int i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


ll calc(ll x, ll k, ll m)
{
    if(x == m || m == 1)
    {
        return 0;
    }

    if(k == 1)
    {
        return x % m;
    }

    return power(x,calc(x,k-1,phi[m]),m);
}

int main()
{
    ll i, j, l, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    computeTotient(10000001);

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll x, k, m;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(x);
        slld(k);
        slld(m);

        plld(calc(x, k, m));
    }


}

