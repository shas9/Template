struct crt
{
    ll n;
    vector < ll > m, r;

    void init(ll _n)
    {
        n = _n;
        m.resize(n);
        r.resize(n);
    }

    pll ext_euclid(ll a, ll b)
    {
        pll ret = {0,0};

        ll x1 = 0, y1 = 1;
        ll x2 = 1, y2 = 0;

        ll r3, r0;

        for(ll r1 = b, r2 = a; r1 ; r2 = r1, r1 = r3)
        {
            r0 = r2 / r1;
            r3 = r2 % r1;

            ll x3 = (x2 - (x1 * r0));
            ll y3 = (y2 - (y1 * r0));

            x2 = x1, y2 = y1;
            x1 = x3, y1 = y3;
        }

        return {x2,y2};
    }

    ll lcm(ll a, ll b)
    {
        ll ret = a / __gcd(a,b);
        return ret * b;
    }

    ll mul(__int128 a, __int128 b, __int128 m)
    {
        __int128 ret = ((a % m) * (b % m)) % m;

        return (long long) ret;
    }

    pll start()
    {
        ll r1 = r[0], m1 = m[0];

        for(ll i = 1; i < n; i++)
        {
            ll r2 = r[i], m2 = m[i];
            ll g = __gcd(m1,m2);

            if(r2 % g != r1 % g) return {-1,-1};

            pll ans = ext_euclid(m1/g,m2/g);

            ll md = lcm(m1,m2);

            ll x = (mul(mul(r2,m1/g,md),ans.first,md) + mul(mul(r1,m2/g,md),ans.second,md)) % md;

            r1 = x, m1 = md;

            if(r1 < 0) r1 += md;
        }

        return {r1,m1};
    }
};
