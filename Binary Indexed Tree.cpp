struct BIT
{
       ll tree[mx];
       ll query(ll idx)
       {
              ll sum=0;
              while(idx>0){
                    sum+=tree[idx];
                    idx -= idx & (-idx);
              }
              return sum;
       }

       void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
       {
              while(idx<=n)
              {
                    tree[idx]+=x;
                    idx += idx & (-idx);
              }
       }
};
