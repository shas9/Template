ll arr[mx];
ll tree[mx*3];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];


}

void update(ll node, ll b, ll e, ll i, ll val)
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

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

ll sum(ll node, ll b, ll e, ll i, ll j)
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

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return p1 + p2;


}
