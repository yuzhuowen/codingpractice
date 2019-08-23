#include <iostream>
#include<cstring>
using namespace std;
char s[50];

int main()
{
    int t;
    cin>>t;
    for(; t>0; --t)
    {
        int n,*p_sequence,*w_sequence;
        cin>>n;
        p_sequence=new int[n];
        w_sequence=new int[n];
        int l=0,q=0;
        cin>>p_sequence[0];
        for(int j=0; j<p_sequence[0]; ++j)
        {
            s[l++]='(';

        }
        s[l++]=')';
        for(int i=1; i<n; ++i)
        {
            cin>>p_sequence[i];
            for(int j=0; j<p_sequence[i]-p_sequence[i-1]; ++j)
            {
                s[l++]='(';

            }
            s[l++]=')';
        }
        int len=strlen(s),m,p;
        for(int i=0; i<len-1; ++i)
        {
            if(s[i]==')')
            {   p=1;
                while(1)
                {
                    m=1;
                    if(s[i-m]=='e')
                    {
                        ++p;
                    }
                    if(s[i-m]=='(')
                    {
                        s[i]='f';
                        s[i-m]='e';
                        w_sequence[q++]=p;
                        cout<<w_sequence[q-1]<<" "<<endl;
                        //cout<<s;
                        break;

                    }
                    ++m;
                }
            }
        }

/*        for(int i=0; i<n; ++i)
        {
            cout<<w_sequence[i]<<" ";
        }
        cout<<endl;*/
        delete []p_sequence;
        delete []w_sequence;
    }
    return 0;
}
