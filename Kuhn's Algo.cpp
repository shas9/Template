// Complexity: O(n*m)
// Connection from left to right
// Direction from right to left
 
 
ll n, k; // n = right part size, k = left part size;
vector < ll > g[1500];
vector < ll > lftp, rgtp;
vector < bool > used;
 
bool try_kuhn(ll v)
{
    for (ll to : g[v])
    {
        if(used[to]) continue;
        used[to] = 1;
 
        if (lftp[to] == -1 || try_kuhn(lftp[to]))
        {
            lftp[to] = v;
            rgtp[v] = to;
            return true;
        }
    }
    return false;
}
 
 
void kuhn()
{
    lftp.assign(k, -1);
    rgtp.assign(n, -1);
 
    for (ll v = 0; v < n; ++v)
    {
        used.assign(n, false);
        try_kuhn(v);
    }
 
//    for (ll i = 0; i < k; ++i)
//            printf("%d %d\n", lftp[i], i);
//
//    for (ll i = 0; i < k; ++i)
//            printf("%d %d\n", rgtp[i], i);
 
}
