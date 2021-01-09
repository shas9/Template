struct node
{
    ll l, r, id, blc;
};
 
const ll lim = 100005;
 
node q[lim];
ll ans[lim];
ll freq[3000006];
ll arr[lim];
ll cnt;
 
bool comp(node a, node b)
{
    if(a.blc != b.blc)
    {
        return a.blc < b.blc;
    }
 
    if(a.blc % 2 == 0)
    {
        return a.r < b.r;
    }
    else
    {
        return a.r > b.r;
    }
}
 
void add(ll x)
{
	ll need = arr[x] ^ k;
 
	cnt += freq[need];
 
	freq[arr[x]]++;
}
 
void rem(ll x)
{
	freq[arr[x]]--;
 
	ll need = arr[x] ^ k;
 
	cnt -= freq[need];
}
 
 
// q[i].blc = l / ssq;  /// block count
 
/*
	l = 1, r = 0, cnt = 0;
 
    while(l > q[i].l) add(--l);
    while(r < q[i].r) add(++r);
    while(l < q[i].l) rem(l++);
    while(r > q[i].r) rem(r--);
*/
