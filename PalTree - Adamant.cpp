const int MAXN = 2e6 + 666;
 
struct palindromic_tree
{
    int len[MAXN], link[MAXN], cnt[MAXN];
    char S[MAXN];
    vector<pair<char, int>> to[MAXN];
 
    int n, last, sz;
 
    void clear()
    {
        fill(to, to + MAXN, vector<pair<char, int>>());
        memset(len , 0, sizeof(len ));
        memset(link, 0, sizeof(link));
        memset(cnt , 0, sizeof(cnt ));
        memset(S   , 0, sizeof(S   ));
        n = last = 0;
        link[0] = 1;
        len[1] = -1;
        S[n++] = 27;
        sz = 2;
    }
 
    palindromic_tree()
    {
        clear();
    }
 
    int get_link(int v)
    {
        while(S[n - len[v] - 2] != S[n - 1]) v = link[v];
        return v;
    }
 
    int tr(int v, int c)
    {
        for(auto it: to[v])
            if(it.first == c) return it.second;
        return 0;
    }
 
    int add_letter(int c)
    {
        S[n++] = c;
        int cur = get_link(last);
        if(!tr(cur, c))
        {
            len [sz] = len[cur] + 2;
            link[sz] = tr(get_link(link[cur]), c);
            to[cur].push_back({c, sz++});
        }
        last = tr(cur, c);
        return cnt[last] = cnt[link[last]] + 1;
    }
}
