#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int l,n;
    double c;
    while(cin>>l>>n>>c)
    {
        if(l<0&&n<0&&c<0)
        {
            break;
        }
        double s0=(1+n*c)*l,s,r,h,low=0.0,high=(double)l/2,mid;

        while(high-low>=1e-5)//精度
        {mid=(low+high)/2.0;
            r=(double)l*l/8.0/mid+mid/2;
         s=2*r*asin(l/2.0/r);
         s<s0?low=mid:high=mid;
        }
        h=mid;
        cout<<fixed<<setprecision(3)<<h<<endl;//小数点后三位


    }
    return 0;
}
