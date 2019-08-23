#include <cstring>
#include <iostream>
using namespace std;

int main()
{  char s[300];
   int i=0;
   while(s[i]!='#')
    {
       int sum=0;
       for( i=0;i<strlen(s);i++)
       {   cin>>s[i];
           if(s[i]>='A'&&s[i]<='Z')
                sum +=(s[i]-'A'+1)*(i+1);
       }
       cout<<sum;
    }

   return 0;
}
