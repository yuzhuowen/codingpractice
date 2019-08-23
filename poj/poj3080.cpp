#include <iostream>

#include <cstring>

using namespace std;

int main()
{
    int t,n;
    int i,j,k;
    char str[11][65],ans[65],strm[65];
    cin>>t;
    while (t--)
    {
        ans[0]='\0';
        cin>>n;
        for (i=0;i<n;i++)
        {
            cin>>str[i];
        }
        for (int len=3;len<=60;len++)
        {
            for (j=0;j<=60-len;j++)
            {
                strm[0]='\0';
                for (k=j;k<j+len;k++)
                {
                    strm[k-j]=str[0][k];
                }
                strm[len]='\0';
                for (i=1;i<n;i++)
                {
                    char *p=strstr(str[i],strm);
                    if(p==NULL) break;
                }
                if(i==n)
                {
                    if(ans[0]=='\0') strcpy(ans,strm);
                    else if(strlen(ans)==strlen(strm))
                    {
                        if(strcmp(ans,strm)>0)
                            strcpy(ans,strm);
                    }
                    else if(strlen(ans)<strlen(strm))
                    {
                        strcpy(ans,strm);
                    }
                }
            }
        }
        if(ans[0]=='\0') cout<<"no significant commonalities";
        else
        cout<<ans;
    }
    return 0;
}
