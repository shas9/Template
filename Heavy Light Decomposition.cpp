/// Template: HLD

/* DFS for Heavy-Light Decomposition
 * head[u] = Head of the chain of node u
 * Operations can be performed in [in[head[u]],in[u]] range.
 * As DFS-time is used, [in[u],out[u]] range can be used
   for performing operations on the subtree of node u.
*/

const ll maxn = 30000;
const ll ln = 16;


vector < ll > g[maxn + 10];
ll parent[ln + 2][maxn + 10];
ll depth[maxn + 10];
ll subtree[maxn + 10];
ll head[maxn + 10];
ll intime[maxn + 10];
ll outtime[maxn + 10];
ll cur_pos;

void dfs(ll node, ll par, ll d)
{
    parent[0][node] = par;
    depth[node] = d;
    subtree[node] = 1;

    for(auto &it: g[node])
    {
        if(it != par)
        {
            dfs(it, node, d + 1);

            subtree[node] += subtree[it];

            if(subtree[it] > subtree[g[node].front()])
            {
                swap(it, g[node].front());
            }
        }
    }

    return;
}

void decompose(ll node, ll par)
{
    if(node == 1) head[node] = 1;
    intime[node] = ++cur_pos;

    for(auto it: g[node])
    {
        if(it != par)
        {
            head[it] = (it == g[node].front()? head[node] : it);
            decompose(it, node);
        }
    }

    outtime[node] = cur_pos;
    return;
}

void init(ll n)
{
    for(ll i = 0; i <= n; i++)
    {
        for(ll j = 0; j < ln; j++)
        {
            parent[j][i] = -1;
        }
    }

    cur_pos = 0;

    dfs(1, -1, 0);
    decompose(1, -1);

    for(ll i = 1; i < ln; i++) // LCA - part
    {
        for(ll j = 1; j <= n; j++)
        {
            if(parent[i - 1][j] != -1)
            {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    return;
}

ll lca(ll u, ll v)
{
    if(depth[u] < depth[v]) swap(u, v);

    ll diff = depth[u] - depth[v];

    for(ll i = 0; i < ln; i++) if(check(diff,i)) u = parent[i][u];

    if(u == v) return u;

    for(ll i = ln - 1; i >= 0; i--)
    {
        if(parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

ll query_chain(ll u, ll v)
{
    ll now = -1;
    ll ret = 0;

    while(now != u)
    {
        now = head[v];

        if(depth[now] < depth[u]) now = u;

        ret += seg.query(intime[now], intime[v]);
        v = parent[0][now];
    }

    return ret;
}

ll query(ll u, ll v)
{
    ll xlca = lca(u,v);

    ll ret = query_chain(xlca, u) + query_chain(xlca, v);

    ret -= query_chain(xlca, xlca);

    return ret;
}
