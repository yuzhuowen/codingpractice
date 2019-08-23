#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[10000][15],s2[15],s3[15];
    int l[10000]= {0},record[10000];
    int i=0;
    bool flag;
    while(1)
    {
        cin>>s[i];
        if(s[i][0]=='#')
        {
            break;
        }
        l[i]=strlen(s[i]);
        ++i;

    }
    while(1)
    {
        cin>>s2;
        if(s2[0]=='#')
        {
            break;
        }
        flag=false;
        int m=0;
        memset(record,-1,sizeof(record));
        int l2=strlen(s2),count;
        for(int j=0; j<i; ++j)
        {   int u;
            switch(l2-l[j])
            {
            case 0:
                count=0;
                for(int t=0; t<l2; ++t)
                {
                    if(s2[t]!=s[j][t])
                    {
                        count++;
                    }
                    if(count>1)
                    {
                        break;
                    }
                }
                if(count==0)
                {
                    cout<<s2<<" is correct"<<endl;
                    flag=true;
                }
                else
                {
                    if(count==1)
                    {
                        record[m++]=j;
                    }
                }
                break;
            case -1:

            for(int k=0;k<l[j];++k)
            {   u=0;
                memset(s3,'\0',sizeof(s3));
                for(int n=0;n<l[j];++n)
                {
                    if(n!=k)
                    {
                        s3[u++]=s[j][n];
                    }
                }
                if(strcmp(s3,s2)==0)
                {
                    record[m++]=j;
                    break;
                }
            }
            break;
            case 1:
            for(int k=0;k<l2;++k)
            {   u=0;
                memset(s3,'\0',sizeof(s3));
                for(int n=0;n<l2;++n)
                {
                    if(n!=k)
                    {
                        s3[u++]=s2[n];
                    }
                }
                if(strcmp(s3,s[j])==0)
                {
                    record[m++]=j;
                    break;
                }
            }
            break;
            default:
                break;
            }
            if(flag)
            {
                break;
            }
        }
        if(!flag)
        {   cout<<s2<<":";
            for(int k=0; record[k]!=-1;++k)
            {
                cout<<" "<<s[record[k]];
            }
            cout<<endl;
        }
    }
    return 0;
}
