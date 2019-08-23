#include <iostream>

using namespace std;

int main()
{
    int n,m,*s,low=0,high=0,mid;
    cin>>n>>m;
    s=new int[n];
    for(int i=0; i<n; ++i)
    {
        cin>>s[i];
        if(s[i]>low)
        {
            low=s[i];
        }
        high+=s[i];
    }
    while(high>low)
    {
        mid=(low+high)/2;
        int num=0,sum=0;
        for(int i=0; i<n; ++i)
        {
            if(sum+s[i]>mid)
            {
               num++;
               sum=0;
            }
            sum+=s[i];
        }
        ++num;
        //cout<<low<<" "<<high<<" "<<num<<endl;
        num>m?low=mid+1:high=mid;//整数，这一步关键
    }
    cout<<mid<<endl;
    delete s;
    return 0;
}
