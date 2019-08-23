#include <iostream>

using namespace std;

int main()
{
    int n,mid,max=0,p[10000]={0},sum=0;
    cin>>n;
    int*s=new int[n];
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        ++p[s[i]];
    }
    for(int i=0;i<10000;++i)
    {
        if(p[i]!=0)
        {
            sum+=p[i];
        }
        if(sum>=(n+1)/2)
        {
            cout<<i;
            break;
        }
    }
    delete s;
    return 0;
}
