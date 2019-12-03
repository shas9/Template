ll uppell(ll n)
{
    ll high =  el.size() - 1;
    ll low = 0;
    ll ans = high;

    while(low <= high)
    {
        ll mid = low + high;
        mid /= 2;

        if(el[mid] == n)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(el[mid] > n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
ll lowell(ll n)
{
    ll high = el.size() - 1;
    ll low = 0;
    ll ans = 0;

    while(low <= high)
    {
        ll mid = low + high;
        mid /= 2;

        if(el[mid] == n)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(el[mid] > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}