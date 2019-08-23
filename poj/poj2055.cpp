#include<cstring>
#include<iostream>
using namespace std;
void bulid(int n,char *s1,char *s2)
{
    if(n<=0)  return ;
    int p=strchr(s2,s1[0])-s2;
    bulid(p,s1+1,s2);
    bulid(n-p-1,s1+p+1,s2+p+1);
    cout<<s1[0];
}
int main()
{
    char s1[110],s2[110];
    while(1)
    {   cin>>s1;
        cin>>s2;
        int n=strlen(s1);
        bulid(n,s1,s2);
        cout<<endl;
    }
    return 0;

}
