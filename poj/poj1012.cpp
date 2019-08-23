#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int k,m,record[10]= {0},s,j=0;
    bool flag;
    while(1)
    {
        cin>>k;
        if(k==0)
        {
            break;
        }

        flag=false;
        for(m=k+1;;++m)
        {
            s=0;
            int i=0;
            while(1)
            {
                s=(s+m-1)%(2*k-i);
                //cout<<"ans["<<i<<"]="<<ans[i];
                ++i;
                if(s<k)
                {
                    if(i==k)
                    {
                        flag=true;
                    }
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        record[j++]=m;

    }
    for(int i=0; record[i]!=0; ++i)
    {
        cout<<record[i]<<endl;
    }
    return 0;
}
