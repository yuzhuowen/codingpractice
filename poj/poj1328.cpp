#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int n,d,x,y,j,min_num,t=0;
    while(1)
    {
        ++t;
        min_num=1;
        cin>>n>>d;
        if(n==0&&d==0)
        {
            break;
        }
        double**island=new double*[n];

        for(int i = 0; i < n; i++)
        {
            island[i] = new double [2];
        }
        for(int i=0; i<n; ++i)
        {
            cin>>x>>y;
            if(y<0||y>d||d<0)
            {
                min_num=0;
                break;
            }
            if(d==abs(y))
            {
                island[i][0]=island[i][1]=x;
            }
            if(d>abs(y))
            {
                island[i][0]=x*1.0+sqrt(double(d*d-y*y));
                island[i][1]=x*1.0-sqrt(double(d*d-y*y));
            }
        }
        int x0=island[0][0],x1=island[0][1];
         for (int i=1; i<n; ++i)
         {int tmp=a[i];
             for( j=i-1;j>=0;--j)
             {
                a[j+1]=a[j];
             }
             a[j+1]=tmp;
         }
        for (int i=0; i<n; ++i)
        {
            if (island[i][0]> x1)
            {
                ++min_num;
                x0=island[i][0];
                x1=island[i][1];
            }
            else if (island[i][1] < x1)
            {
                x0=island[i][0];
                x1=island[i][1];
            }


        }
      cout<<"case"<<t<<":"<<min_num<<endl;
    }
    return 0;



}
