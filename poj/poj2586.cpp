#include <iostream>

using namespace std;

int main()
{
    int s=1,d=-1,all,month[12];//s,d之前有值
    while(s>0&&d<0)
    {
        int count;
        cin>>s>>d;
        d*=-1;
        all=0;
        for(int i=0; i<12; ++i)
        {
            month[i]=s;
        }
        for(int k=0; k<8; ++k)
        {
            for(int t=k+4; t>=k; --t)
            {
                count=0;
                for(int j=k; j<=k+4; ++j)
                {
                    count+=month[j];
                }
                if(count>=0)
                {
                    month[t]=d;
                }
                else
                {
                    break;
                }

            }

        }
        for(int i=0; i<12; ++i)
        {
            all+=month[i];
        }
        if(all>=0)
        {
            cout<<"Surplus:"<<all<<endl;
        }
        else
        {
            cout<<"Deficit"<<endl;

        }


    }
    return 0;
}
