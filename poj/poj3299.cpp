#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    char a,b;
    double s1,s2,t,d,h,h1,e;
    double tdh[30];
    for(int i=0; i<30; ++i)
    {
        tdh[i]=-101.0;
    }
    for(int i=0; i<30; i+=3)
    {   cout<<"A,num1,B,num2,E 0.0 E 0.0"<<endl;
        cin>>a>>s1>>b>>s2;
        t=d=h=-101.0;
        switch(a)
        {
        case 'T':
            t=s1;
            break;
        case 'D':
            d=s1;
            break;
        case 'H':
            h=s1;
            break;
        case 'E':
            for(int j=0; tdh[j]!=-101.0; j+=3)
            {   cout << setiosflags(ios::fixed) << setprecision(1);
                cout<<"T "<<tdh[j]<<" D "<<tdh[j+1]<<" H "<<tdh[j+2]<<endl;

            }return 0;
        }
        switch(b)
        {
        case 'T':
            t=s2;
            break;
        case 'D':
            d=s2;
            break;
        case 'H':
            h=s2;
            break;
        }
        if(h==-101.0)
        {
            e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(d+273.16))));
            h1= (0.5555) * (e - 10.0);
            h = t + h1;
        }
        if(d==-101.0)
        {
            h1 = h - t;
            e = h1/ 0.5555 + 10.0;
            d = 1 / ((1 / 273.16) - log(e / 6.11) / 5417.7530) - 273.16;
        }
        if(t==-101.0)
        {
            e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(d+273.16))));
            h1= (0.5555) * (e - 10.0);
            t = h - h1;
        }
        tdh[i]=t;
        tdh[i+1]=d;
        tdh[i+2]=h;

}

return 0;
}
