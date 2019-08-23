#include<iostream>
#include<cmath>
using namespace std;
bool isprime ( int k )
{   if(k==2||k==1)return true;
    for ( int i = 2  ; i <= sqrt (k) ; i ++ )
    {

        if ( k % i == 0 )
        {
            return false ;
        }
    }
    return true ;

}
int main()

{
    int n ;
    while (cin>>n )
    {
        int i ;
        int t = n / 2 ;
        for ( i = 3 ; i <= t ; i += 2 )
            if ( isprime ( i ) && isprime ( n - i ) )
                break ;
        cout<<n<<"="<<i<<"+"<<n-i<<endl ;

    }
    return 0;

}
