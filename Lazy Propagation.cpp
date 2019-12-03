
#define mx 100005

struct info
{
    ll prop, summ;
} tree[mx*3];

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].summ += (e - b + 1) * val;
        tree[node].prop += val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node].summ = tree[left].summ + tree[right].summ + (e - b + 1) * tree[node].prop;
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].summ + carry * (e - b + 1);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = sum(right, mid + 1, e,i, j, carry + tree[node].prop);

    return p1 + p2;
}




