ll arr[lim * 2];
vector < ll > tree[4 * 2 * lim];

void merge_sort(ll node, ll a, ll b) {
	if (a == b) {
		tree[node].pb(arr[a]);
		return;
	}
	ll mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;
	merge_sort( left, a, mid);
	merge_sort( right, mid + 1, b);

	merge( tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

ll up( ll valu, ll node ) {
	//cout<<valu<<' '<<node<<endl;
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = 0;

	while ( l <= r ) {
		mid = (l + r) / 2;
		if ( tree[node][mid] <= valu ) {
			pos = mid + 1;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}


	return pos;
}

ll down( ll valu, ll node )
{
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = tree[node].size();

	while ( l <= r )
    {
		mid = (l + r) / 2;
		if ( tree[node][mid] > valu ) {
			pos = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}


	return tree[node].size() - pos;
}

ll query(ll node, ll a, ll b, ll i, ll j, ll val) {
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {

		ll ret = 0;
		if ( tree[node].size() )
			ret = up( val, node );
		//scout<<"ret "<<ret<<endl;
		return ret;

	}
	ll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query( left , a, mid, i , j , val );
	r2 = query( right , mid + 1 , b, i, j, val);
	return r1 + r2;

}
