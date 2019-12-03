#define MAXN 1000000
#define SQRSIZE 1000

ll arr[MAXN];
ll block[SQRSIZE];
ll blk_sz;

void update(ll idx, ll val)
{
    ll blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}


ll query(ll l, ll r)
{
    ll sum = 0;
    while (l < r && l % blk_sz != 0 && l != 0)
    {
        sum += arr[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l <= r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}

void preprocess(ll n)
{
    ll blk_idx = -1;

    blk_sz = sqrt(n);



    for(ll i = 0; i < SQRSIZE; i++) block[i] = 0;

    for (ll i = 0; i < n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}
