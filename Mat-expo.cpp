
const ll msz = 2;
const ll mod = ---;
struct matexpo
{
    ll mat[msz][msz];
    ll tmp[msz][msz];
    ll res[msz][msz];

    ll cn = msz, rn = msz;

    void mult(ll p)
    {
		for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[i][j];

        for(ll i = 0; i < rn; i++)
        {
            for(ll j = 0; j < cn; j++)
            {
                res[i][j] = 0;
                for(ll k = 0; k < cn; k++)
                {
                    res[i][j] = (res[i][j] + (tmp[i][k] * tmp[k][j])) % mod;
                }
            }
        }

        if(p & 1)
        {
			for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[i][j];
            for(ll i = 0; i < rn; i++)
            {
                for(ll j = 0; j < cn; j++)
                {
                    res[i][j] = 0;
                    for(ll k = 0; k < cn; k++)
                    {
                        res[i][j] = (res[i][j] + (mat[i][k] * tmp[k][j])) % mod;
                    }
                }
            }
        }
    }

    void expo(ll pwr)
    {
        if(pwr == 0)
        {
            for(ll i = 0; i < rn; i++)
            {
                for(ll j = 0; j < cn; j++)
                {
					res[i][j] = (i == j); // identity matrix
                }
            }

            return;
        }

        expo(pwr / 2);

        mult(pwr);
    }
};
