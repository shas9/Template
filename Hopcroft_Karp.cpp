namespace hkarp
{
	const ll MaxLeftNodes = 50000;
	const ll MaxRightNodes = 50000;
	const ll MaxEdges = 150000;

	ll LeftNodesNo, RightNodesNo, edges;
	ll last[MaxLeftNodes], previous[MaxEdges], to[MaxEdges];
	ll matching[MaxRightNodes], dist[MaxLeftNodes], Q[MaxLeftNodes];
	bool used[MaxLeftNodes], vis[MaxLeftNodes];

	void init(ll _LeftNodesNo, ll _RightNodesNo)
	{
		LeftNodesNo = _LeftNodesNo;
		RightNodesNo = _RightNodesNo;
		edges = 0;
		fill(last, last + LeftNodesNo + 1, -1);
	}

	void addedge(ll u, ll v)
	{
		to[edges] = v;
		previous[edges] = last[u];
		last[u] = edges++;
	}

	void bfs()
	{
		fill(dist, dist + LeftNodesNo + 1, -1);
		ll QueueSize = 0;
		for (ll u = 1; u <= LeftNodesNo; ++u)
		{
			if (used[u] == 0)
			{
				Q[QueueSize++] = u;
				dist[u] = 0;
			}
		}
		for (ll i = 0; i < QueueSize; i++)
		{
			ll u1 = Q[i];
			for (ll e = last[u1]; e >= 0; e = previous[e])
			{
				ll u2 = matching[to[e]];
				if (u2 >= 0 && dist[u2] < 0)
				{
					dist[u2] = dist[u1] + 1;
					Q[QueueSize++] = u2;
				}
			}
		}
	}

	bool dfs(ll u1)
	{
		vis[u1] = 1;
		for (ll e = last[u1]; e >= 0; e = previous[e])
		{
			ll v = to[e];
			ll u2 = matching[v];
			if (u2 < 0 || vis[u2] == 0 && dist[u2] == dist[u1] + 1 && dfs(u2))
			{
				matching[v] = u1;
				used[u1] = 1;
				return 1;
			}
		}
		return 0;
	}

	ll bpm()
	{
		fill(used, used + LeftNodesNo + 1, 0);
		fill(matching, matching + RightNodesNo + 1, -1);
		for (ll res = 0;;)
		{
			bfs();
			fill(vis, vis + LeftNodesNo + 1, 0);
			ll f = 0;
			for (ll u = 1; u <= LeftNodesNo; ++u)
				if (used[u] == 0 && dfs(u))
					++f;
			if (f == 0)
				return res;
			res += f;
		}
	}
}

using namespace hkarp;
