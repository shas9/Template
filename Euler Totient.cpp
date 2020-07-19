ll calphi(ll m)
{
	double res = mm;

	for(ll i = 2; i * i <= mm; i++)
	{
		if(mm % i == 0)
		{
			while(mm % i == 0) mm /= i;
			res *= (1.0 - (1.0 / i));
		}
	}

	if(mm > 1) res *= (1.0 - (1.0 / mm));

	return phi = (long long)res;
}
