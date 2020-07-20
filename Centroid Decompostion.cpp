const ll mx = 100005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll dist[mx];
ll n, ans;

vector < ll > g[mx];

void dfs(ll node, ll par)
{
	sz[node] = 1;

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			dfs(it,node);
			sz[node] += sz[it];
		}
	}
}

void calc(ll node, ll par, ll d = 1)
{
	if(d <= k)
	{
		ans += dist[k - d];
	}

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
			calc(it,node, d + 1);
	}
}

void update(ll node, ll par, ll d = 1)
{
	if(d <= k) dist[d]++;

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			update(it,node,d + 1);
		}
	}
}

ll decompose(ll cen)
{
	dfs(cen,-1);

	ll target = sz[cen] / 2;
	ll p = -1;
	bool ok = false;

	while(!ok)
	{
		ok = true;

		for(auto it: g[cen])
		{
			if(it != p && done[it] == false && sz[it] > target)
			{
				ok = false;
				p = cen;
				cen = it;
				break;
			}
		}
	}

	done[cen] = true;

	for(ll i = 0; i <= k; i++) dist[i] = 0;
	dist[0] = 1;

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			calc(it,cen);
			update(it,cen);
		}
	}

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			cenpar[decompose(it)] = cen;
		}
	}

	return cen;
}
