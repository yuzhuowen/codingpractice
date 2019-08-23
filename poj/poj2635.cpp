#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 1000010;
int prime[N+1], cnt = 0;
bool primeflag[N+1];

void primelist()           //素数打表
{
    memset(primeflag,true,sizeof(primeflag));
    int i, j;
    for( i = 2;i < N;i++ )
    {
        if( primeflag[i] )
        {
            prime[cnt++] = i;
            for( j = i+i;j <= N;j += i )
                primeflag[j] = false;
        }
    }
}

int check(char *s,int x)
{
    int i, len, sum;
    len = strlen(s);
    sum = 0;
    for( i = 0;i+3 < len;i += 3 )
    {
        sum = ( sum*1000 + (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0') )%x;           //同余模定理
    }
    while( i<len )//重要
    {
        sum = sum*10 + s[i++] - '0';
    }
    sum %= x;
    return sum;
}

int main()
{
    primelist();
    char s[110];
    int L;
    while( cin>>s>>L )
    {
        if( s[0]=='0'&&L==0 )
            break;

        int flag = 0;

        for( int i = 0;i <cnt&&prime[i]<L;i++ )
        {
            if( !check(s,prime[i]) )
            {
                flag = 1;
                cout<<"BAD "<<prime[i]<<endl;
                break;
            }
        }
        if( !flag )
            cout<<"GOOD"<<endl;

    }

    return 0;
}
