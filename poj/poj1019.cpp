#include <iostream>
#include <cmath>
using namespace std;

int main()
{   int t,n,a[1001],s[1001],num;
    cin>>t;
    a[0]=s[0]=0;
    for(int i=1;i<1001;++i)
    {
        a[i]=a[i-1]+(int)log10(double(i))+1;//求位数
        s[i]=s[i-1]+a[i];
    }
    for(;t>0;--t)
    {   int i=0;
        cin>>n;
        for(i=0;n-s[i]>0;++i);
        int p=n-s[i-1];
        for(int k=1;k<1001;++k)
        {
            p=p-(int)log10(double(k))-1;
            if(p<=0)
            {
                p*=-1;
                //cout<<p;
                num=k/(int)pow((double)10,p)%10;
                break;
            }
        }
        cout<<num<<endl;

    }
    return 0;
}
