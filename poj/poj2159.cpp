#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    char str1[11],str2[11];
    int a[26],b[26],i;

    cout<<"请输入第一个字符串"<<endl;
    cin>>str1;
    cout<<"请输入第二个字符串"<<endl;
    cin>>str2;
    int len1,len2,len;

    len1=strlen(str1);
    len2=strlen(str2);
    if(len1!=len2)
    {
        cout<<"NO!"<<endl;
        return 0;
    }
    else len=len1;
    for(i=0; i<26; ++i)
        a[i]=b[i]=0;
    for(i=0; i<len; ++i)
    {
        ++a[str1[i]-'A'];
        ++b[str2[i]-'A'];
    }
    sort(a,a+26);
    sort(b,b+26);
    for(i=0; i<26; ++i)
    {
        cout<<a[i]<<" "<<b[i]<<endl;
    }
    for(i=0; i<26; ++i)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO!";
            i=0;
            break;
        }

    }
    if(i!=0)
    {
        cout<<"YES!";
    }
    return 0;
}
