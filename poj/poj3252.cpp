#include <iostream>
#include<cstring>
using namespace std;
int c[30][30]= {0};
int count(int x)
{
    int s[10],i=0,sum=0,zero=0;
    while(1)
    {
        if(x<2)
        {
            s[i]=x;
            break;
        }
        s[i++]=x%2;
        x/=2;
    }
    int t=i+1;
    for(int j=2; j<=i; ++j)
    {
        for(int k=j/2; k<=j-1; ++k)
        {
            sum+=c[j-1][k];
        }
    }
    for(int j=t-1; j>1; --j)
    {
        if(s[j]==0)
        {
            zero++;
            continue;
        }
        else
        {  int x=zero-t/2+1+j<0?0:zero-t/2+1+j;//x不能从负开始
           for(;x<=j-1;++x)
           {
               sum+=c[j-1][x];
           }
        }
    }

    return sum;
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0; i<30; i++)
    {
        c[i][0]=1;
        c[i][i]=1;
        for(int j=1; j<i; j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    cout <<count(n+1)-count(m)<< endl;
    return 0;
}
