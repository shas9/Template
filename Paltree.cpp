const ll N = (1e5) + 10;

ll tree[N][26];
ll len[N];
ll link[N];
char s[N]; // 1 indexed;

ll idx = 0, t = 0;

void init()
{
    while(idx)
    {
        for(ll i = 0; i < 26; i++) tree[idx][i] = 0;
        len[idx] = link[idx] = 0;
        idx--;
    }

    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    idx = t = 2;
}

void extend(ll p)
{
    while(s[p - len[t] - 1] != s[p]) t = link[t];

    ll x = link[t];
    ll c = s[p] - 'a';

    while(s[p - len[x] - 1] != s[p]) x = link[x];

    if(!tree[t][c])
    {
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2;
        link[idx] = (len[idx] == 1) ? 2 : tree[x][c];
    }

    t = tree[t][c];
}
