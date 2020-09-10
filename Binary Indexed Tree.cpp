struct BIT
{
       vector < ll > tree;
       ll n;

       BIT(ll n) : n(n), tree(n + 3, 0) {}

       void init()
       {
			tree.assign(n + 3, 0);
       }

       ll query(ll idx)
       {
              ll sum=0;
              while(idx>0){
                    sum+=tree[idx];
                    idx -= idx & (-idx);
              }
              return sum;
       }

       void update(ll idx, ll x) //n is the size of the array, x is the number to add
       {
              while(idx<=n)
              {
                    tree[idx]+=x;
                    idx += idx & (-idx);
              }
       }
} bit(300002);
