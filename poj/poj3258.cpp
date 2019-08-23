#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l,n,m,low,high,mid,num,sum=0;
    cin>>l>>n>>m;
    int *distance=new int[n];
    int *d=new int[n+1];
    for(int i=0; i<n; ++i)
    {
        cin>>distance[i];
    }
    sort(distance,distance+n);
    d[0]=distance[0];
    d[n]=l-distance[n-1];
    low=d[0]<d[n]?d[0]:d[n];
    high=l;
    for(int i=1; i<=n-1; ++i)
    {
        d[i]=distance[i]-distance[i-1];
        if(d[i]<low)
        {
            low=d[i];
        }
    }
    while(low<=high)
    {
        mid=(low+high)/2;
        sum=num=0;
        for(int i=0;i<n; ++i)
        {
            sum+=d[i];
            if(sum<mid)
            {
                num++;
            }
            else
            {
                sum=0;
            }
        }
        num>m?high=mid:low=mid+1;
    }
    cout<<mid<<endl;
    delete distance;
    delete d;
    return 0;
}
