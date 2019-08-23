#include <iostream>

using namespace std;

int main()
{
    int test,n,maxtime;
    int code[200];
    //cout<<"输入测试用例的数量"<<endl;
    cin>>test;
    for(; test>=0; --test)
    {
        //cout<<"输入移动数量"<<endl;
        cin>>n;
        maxtime=0;
        for(int k=0; k<200; ++k)
        {
            code[k]=0;
        }
        for(int i=0; i<n; ++i)
        {
            int from,to;
            cin>>from>>to;
            from=from<to?from:to;
            to=from>to?from:to;
            from=(from-1)/2;
            to=(to-1)/2;
            for(int j=from; j<to; ++j)
            {
                ++code[j];
            }
        }
        for(int j=0; j<200; ++j)
        {
            maxtime=maxtime>code[j]?maxtime:code[j];
        }
        maxtime*=10;
        cout<<maxtime<<endl;
    }
    return 0;
}
