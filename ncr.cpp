ll nCr(ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

//    ll result = n;
//    for( int i = 2; i <= k; ++i ) {
//        result *= (n-i+1);
//        result /= i;
//    }
//
//    return result;

    ll x = 1, y = 1;

    for(ll i = n - k + 1; i <= n; i++) x *= i, x %= mod;
    for(ll i = 1; i <= k; i++) y *= i, y %= mod;

    return (x / y) % mod;
}
