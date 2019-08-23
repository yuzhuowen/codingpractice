#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int c[30][30],sum=0;
    char s[10];

    for(int i=0; i<30; i++)
    {
        c[i][0]=1;
        c[i][i]=1;
        for(int j=1; j<i; j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    cin>>s;
    int l=strlen(s);
    for(int k=l-1; k>=1; --k)
    {
        sum+=c[26][k];
    }
    /*for(int k=1; k<=s[0]-'a'&&k<=27-l; ++k)
    {
        sum+=c[26-k][l-1];
    }*/
    for(int m=0; m<=l-1; ++m)
    {   int i=1;
        if(m!=0)
        {
            i=s[m-1]-'a'+2;//相当重要，否则会多
        }
        for(;i<=s[m]-'a'&&i<=27-l+m; ++i)
        {
            sum+=c[26-i][l-m-1];
        }
    }
        cout<<sum+1;
    return 0;
}
