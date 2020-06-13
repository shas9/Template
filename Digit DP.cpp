const ll sz = 14;

ll dp[sz + 1][2][2][2][20];
char lft[sz + 1], rgt[sz + 1];

void shft()
{
	scanf("%s%s", lft, rgt);

	ll lenl = strlen(lft);
	ll lenr = strlen(rgt);

	for(ll i = sz - 1; i >= 0; i--)
	{
		if(lenl) lft[i] = lft[lenl -1], lenl--;
		else lft[i] = '0';
	}

	for(ll i = sz - 1; i >= 0; i--)
	{
		if(lenr) rgt[i] = rgt[lenr -1], lenr--;
		else rgt[i] = '0';
	}

	lft[sz] = rgt[sz] = '\0';

	memset(dp,-1,sizeof dp);
}

ll solve(ll pos, bool isbig, bool issmall, bool isvalid, ll zero = 0)
{
	if(pos == 14) return zero;

	ll &ret = dp[pos][isbig][issmall][isvalid][zero];

	if(ret != -1) return ret;

	ll hi = 9;
	ll lo = 0;

	if(issmall == 0) hi = rgt[pos] - '0';
	if(isbig == 0) lo = lft[pos] - '0';

	ret = 0;

	for(ll i = lo; i <= hi; i++)
	{
		bool valid = isvalid;
		if(i) valid = 1;
		ll add = (i == 0 && isvalid);

		if(i < hi)
		{
			if(i > lo) ret += solve(pos + 1, 1, 1, valid, zero + add) ;
			else ret += solve(pos + 1, isbig, 1, valid, zero + add) ;
		}
		else
		{
			if(i > lo) ret += solve(pos + 1, 1, issmall, valid, zero + add) ;
			else ret += solve(pos + 1, isbig, issmall, valid, zero + add) ;
		}
	}

	return ret;
}
