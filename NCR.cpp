const ll sz = 300000;

ll fact[sz + 10];

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


ll nCr(ll n, ll r)
{
    if(r > n) return 0;

    if(n < mod)
    {
        ll z = ((power(fact[r], mod - 2, mod)) * (power(fact[n - r], mod - 2, mod))) % mod;
        return (fact[n] * z) % mod;
    }
    
    /// Lucas Theorem
    vector < ll > N, K;
    
    while(n) N.push_back(n % mod), n /= mod;
    
    while(r) K.push_back(r % mod), r /= mod;
    
    ll ret = 1;
    
    for(ll i = 0; i < K.size(); i++)
    {
        ret = (ret * nCr(N[i],K[i])) % mod;
    }
    
    return ret;
}

void precalc()
{
    fact[0] = 1;

    for(ll i = 1; i <= sz; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}
