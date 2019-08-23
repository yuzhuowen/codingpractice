#include<iostream>
#include<cmath>
using namespace std;
bool isprime ( int k )
{
    if(k==2||k==1)return true;
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
    int a,d,n,j,i;
    while(1)
    {
        cin>>a>>d>>n;
        j=0;
        i=a;
        while(1)
        {
            if(isprime(i)==true)
            {
                ++j;
            }
            if(j==n)
            {
                break;
            }
            i+=d;
        }
        cout<<i<<endl;
    }

    return 0;
}
