// when mod is not prime

ll ncr[1001][1001];

ll nCr(ll n, ll r)
{
	if(r == 0) return 1;
	if(r == 1) return n;
	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

// when mod is prime

const ll sz = 300000;
const ll mod = 998244353;
 
ll fact[sz + 10];
ll invfact[sz + 10];
 
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
        ll z = (invfact[r] * invfact[n - r]) % mod;
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
 
    invfact[sz] = power(fact[sz], mod - 2, mod);
 
    for(ll i = sz - 1; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
 
    return;
}


//for small r

ll nCr(ll n, ll k)
{
    if(k > n) assert(0);

    ll ret = 1;

    for(ll i = (n - k + 1); i <= n; i++) ret = (ret * i) % mod;

    for(ll i = 2; i <= k; i++) ret = (ret * power(i, mod - 2, mod)) % mod;

    return ret;
}
