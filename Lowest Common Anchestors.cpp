const ll K = 10;
const ll N = 203;

ll anc[N][K];
ll depth[N];

void setup(ll u, ll par) { // setup(x,0); where x is the root
    depth[u] = depth[par]+1;

    memset(anc[u],0,sizeof anc[u]);

    anc[u][0] = par;

    for (ll k=1; k<K; k++) anc[u][k] = anc[anc[u][k-1]][k-1];

    for (ll v: g[u]) {
        if (v == par)   continue;
        setup(v, u);
    }
}

ll lca(ll u, ll v) {

    if (depth[u] > depth[v])    swap(u, v);

    for (ll k=K-1; k>=0; k--)
        if (depth[u] + (1<<k) <= depth[v])  v = anc[v][k];

    if (u == v) return u;

    for (ll k=K-1; k>=0; k--)
        if (anc[u][k] != anc[v][k])
            u = anc[u][k], v = anc[v][k];

    return anc[u][0];
}

ll getanc(ll u, ll d) {

    for (ll k=0; k<K; k++)
        if (d & (1<<k))
            u = anc[u][k];

    return u;
}

ll dist(ll u, ll v) {

    ll x = lca(u, v);

    return depth[u] + depth[v] - 2*depth[x];
}
