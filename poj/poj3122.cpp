#include <iostream>
using namespace std;
const double pi=3.1415926;
int main()
{   int t,n,f,num,count;
    cin>>t;
    double r,pie[10000],sum;
    for(;t>=0;--t)
    {cin>>n>>f;
     num=f+1;
     sum=0;
     for(int i=0;i<n;++i)
     {
         cin>>r;
         pie[i]=pi*r*r;
         sum+=pie[i];
     }
     double low=0,high=sum/(double)num,mid;
     while(high-low>=1e-5)
     {count=0;
      mid=(low+high)/2.0;
      for(int i=0;i<n;++i)
      {
          count+=pie[i]/mid;
      }
      count<num?high=mid:low=mid;}
      cout<<mid<<endl;


    }

    return 0;
}

