/*
    Topic: String Stream, Iterator, Next Permutation, Compare
*/

String Stream:

    char line[1000];
    while( gets( line ) )
    {
        stringstream ss( line ); // initializing
        int num; vector< int > v;
        while( ss >> num ) v.push_back( num );
        sort( v.begin(), v.end() );
    }

Iterator:

    vector< int > :: iterator i;
    for( i = v.begin(); i < v.end(); i++ )
    {
        printf("%d\n", *i);
    }

Permutation:

    vector< int > v;
    for(int i=0; i<11; i++) v.push_back( i );

    do
    {
        //Function
    }
    while(next_permutation(v.begin(), v.end()));

Compare:

    bool compare( data a, data b )
    {
        if( a.income == b.income ) {
            if( a.height == b.height ) {
                if( a.weight == b.weight )

                  return strlen( a.name ) < strlen( b.name );
                else return a.weight < b.weight;
            }else return a.height > b.height;
        }else return a.income > b.income;
    }

    sort( v.begin(), v.end(), compare );


