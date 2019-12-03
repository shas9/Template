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

    tree[node] = min(tree[left],tree[right]);

}

ll solve(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return -1;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = solve(left, b, mid, i, j);
    ll p2 = solve(right, mid + 1, e, i, j);

    if(p1 >= 0 && p2 >= 0)
    {
        return min(p1,p2);
    }
    else if(p1 == -1)
    {
        return p2;
    }
    else
    {
        return p1;
    }
}
