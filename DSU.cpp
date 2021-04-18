const ll N = 2e5+7;
struct DSU {
    ll rep[N], sz[N];

    void init() {
        for (ll i=0; i<N; i++)
            rep[i] = i, sz[i] = 1;
    }

    ll find(ll u) {
        while(rep[u] != u)  u = rep[u];
        return u;
    }

    bool merge(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u == v)   return false;

        if (sz[u] < sz[v])    swap(u, v);
        rep[v] = u;
        sz[u] += sz[v];

        return true;
    }
} dsu;
