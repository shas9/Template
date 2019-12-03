/*trie part*/
struct Trie
{
    ll endmark;
    Trie *Next[2];
    Trie()
    {
        endmark=0;
        for(ll i=0; i<2; i++) Next[i]=NULL;
    }
}*root;

void insert(Trie *curr,ll val)
{
    for(ll i=21;i>=0;i--)
    {
        ll id=check(val,i);
        if(curr->Next[id]==NULL)
            curr->Next[id]=new Trie();
        curr=curr->Next[id];
    }
    curr->endmark=val;
}
ll search(Trie *curr,ll val)
{
    for(ll i=21;i>=0;i--)
    {
        ll id=check(val,i);
        if (curr->Next[id^1] != NULL)curr=curr->Next[id^1];
        else curr=curr->Next[id];
    }
    return val^curr->endmark;
}
/*end of trie part*/
