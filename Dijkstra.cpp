#define nsz 100100 //take maximum nodes + some number

struct dijkstra
{
    ll dis[nsz];
    vector<ll> ed[nsz], cost[nsz];

    void addedge(ll u, ll v, ll c)
    {
		ed[u].pb(v);
		cost[u].pb(c);
    }

    void solve(ll src, ll dst)
    {
        ll i, j, ad, u;

        for(i=0; i< nsz; i++)
        {
            dis[i] = mxlld-100000;
        }

        priority_queue <pll, vector<pll>, greater <pll> > pq;

        pq.push(pll(0, src));

        dis[src] = 0;

        while(!pq.empty())
        {
            pll v = pq.top();
            u = v.second;
            //if (v.first >= lv[u]) continue;
            pq.pop();
            if(u == dst)
                return;
            for(i = 0; i < ed[u].size(); i++)
            {
                ad = ed[u][i];
                if(dis[u] + cost[u][i] < dis[ad])
                {
                    dis[ad]=dis[u]+cost[u][i];
                    pq.push(pll(dis[ad], ad));
                }
            }
        }
    }

};
