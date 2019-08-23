#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    char input[110];
    int num[110]={0},l,length;
    while(1)
    {
        cin>>input;
        l=strlen(input)-1;
         if(input[0]=='0'&&l==0) break;
        length=0;
        for(; l>=0; --l)
        {
            num[length]+=(input[l]-'0');
            length++;
        }
    }
    for(int i=0;i<110;++i)
    {
        if(num[i]>=10)
        {
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
    }
    for(length=109;num[length]==0;--length);
   //length前面没有减1
    for(int i=length; i>=0; --i)
    {
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}
