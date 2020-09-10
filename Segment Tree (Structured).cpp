const ll N = 100005;
ll arr[N];

struct segtree
{
    ll tree[N * 4];
    ll n;

    void treeinit(ll node, ll b, ll e)
    {
        if(b == e)
        {
            tree[node] = arr[b];
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeinit(left, b, mid);
        treeinit(right, mid + 1, e);

        tree[node] = tree[left] + tree[right];
    }

    void init(ll _n)
    {
        n = _n;

        memset(tree,0,sizeof tree);
        treeinit(1,1,n);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = val;
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = tree[left] + tree[right];
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return 0;
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return p1 + p2;
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

};
