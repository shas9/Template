struct scc
{
    ll n;
    ll comp;

    vector < vector < ll > > g, rg;
    vector < ll > compno;
    vector < bool > vis;
    vector < ll > nodes;

    void init(ll _n)
    {
		n = _n;
		g.assign(n + 10, {});
		rg.assign(n + 10, {});
		comp = 0;
		compno.assign(n + 10, 0);
		vis.assign(n + 10, 0);
		nodes.clear();
    }

    void dfs1(ll node)
    {
		vis[node] = 1;

		for(auto it: g[node])
		{
			if(vis[it] == 0) dfs1(it);
		}

		nodes.push_back(node);
    }

    void dfs2(ll node)
    {
		compno[node] = comp;

		for(auto it: rg[node])
		{
			if(compno[it] == 0) dfs2(it);
		}
    }

    void addedge(ll u, ll v)
    {
		g[u].push_back(v);
		rg[v].push_back(u);
    }

    void start()
    {
		for(ll i = 1; i <= n; i++)
		{
			if(vis[i] == 0) dfs1(i);
		}

		reverse(nodes.begin(),nodes.end());

		for(auto it: nodes)
		{
			if(compno[it] == 0)
			{
				comp++;

				dfs2(it);
			}
		}
    }

};

