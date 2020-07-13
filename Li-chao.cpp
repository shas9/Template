struct Line
{
    ll m, c;
};

struct Lichao
{
    vector < Line > tree;
    vector < ll > pnt;
    vector < ll > current;
    ll state;

    ll n;
    ll type;

    Lichao (): pnt(0,0) {}

    void init(ll _t)
    {
		sort(pnt.begin(),pnt.end());

        pnt.erase(unique(pnt.begin(),pnt.end()), pnt.end());

        n = pnt.size() - 1;

        tree.clear();
        tree.resize(4 * (n + 5));

        current.clear();
        current.resize((n + 5));

        state = 1;

        type = _t; // 1 = maximum, 2 = minimum

        if(type & 1) for(ll i = 0; i < tree.size(); i++) tree[i] = {0,mnlld};
        else for(ll i = 0; i < tree.size(); i++) tree[i] = {0,mxlld};
    }

    inline ll f(Line &line, ll &x)
    {
        return line.m*x + line.c;
    }

    void add1(ll lo, ll hi, Line line, ll node)
    {
		if(current[node] != state)
		{
			tree[node] = {0,mnlld};
			current[node] = state;
 		}

        if(lo == hi)
        {
            if(f(line, pnt[lo]) > f(tree[node], pnt[lo]))
                tree[node] = line;
            return;
        }

        ll mid = lo+hi >> 1;

        bool left = f(line, pnt[lo]) > f(tree[node], pnt[lo]);
        bool m = f(line, pnt[mid]) > f(tree[node], pnt[mid]);

        if(m) swap(line, tree[node]);

        if(left != m) add1(lo, mid, line, node<<1);
        else add1(mid+1, hi, line, node<<1|1);
    }

    void add2(ll lo, ll hi, Line line, ll node)
    {
		if(current[node] != state)
		{
			tree[node] = {0,mxlld};
			current[node] = state;
 		}

        if(lo == hi)
        {
            if(f(line, pnt[lo]) < f(tree[node], pnt[lo]))
                tree[node] = line;
            return;
        }

        ll mid = lo+hi >> 1;

        bool left = f(line, pnt[lo]) < f(tree[node], pnt[lo]);
        bool m = f(line, pnt[mid]) < f(tree[node], pnt[mid]);

        if(m) swap(line, tree[node]);

        if(left != m) add2(lo, mid, line, node<<1);
        else add2(mid+1, hi, line, node<<1|1);
    }

    void update(ll m, ll c)
    {
        Line x;
        x.m = m;
        x.c = c;

        if(type & 1) add1(0,n,x,1);
        else add2(0,n,x,1);
    }

    ll query1(ll lo, ll hi, ll idx, ll node)
    {
        if(lo == hi)
            return f(tree[node], pnt[idx]);

        ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

        if(idx <= mid && current[node << 1] == state) return max(ret, query1(lo, mid, idx, node<<1));
        else if(idx > mid && current[node << 1 | 1] == state) return max(ret, query1(mid+1, hi, idx, node<<1 | 1));

        return ret;
    }

    ll query2(ll lo, ll hi, ll idx, ll node)
    {
        if(lo == hi)
            return f(tree[node], pnt[idx]);

        ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

        if(idx <= mid && current[node << 1] == state)return min(ret, query2(lo, mid, idx, node<<1));
        else if(idx > mid && current[node << 1 | 1] == state) return min(ret, query2(mid+1, hi, idx, node<<1 | 1));

        return ret;
    }

    ll ask(ll x)
    {
		ll pos = lower_bound(pnt.begin(),pnt.end(),x) - pnt.begin();

        if(type & 1) return query1(0,n,pos,1);
        else return query2(0,n,pos,1);
    }
};

