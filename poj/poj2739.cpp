#include <iostream>
#include<cstring>
int n;
using namespace std;
void find(int num,int*l,int*c,int**area_state)
{
    int i,j;
    for( i = 0; i <n; i++)
    {
        for( j=0; j<n; ++j)
        {
            if(area_state[i][j]==num)
            {
                *l=i;
                *c=j;
                return;
            }
        }
    }
}
void resume(int num,int**area_state)
{
    int t,num_l,num_c;
    find(num,&num_l,&num_c,area_state);
    for(int i=num_c+1; area_state[num_l][i]!=-1; ++i)
    {
        t=area_state[num_l][i];
        area_state[num_l][i]=-1;
        if(area_state[t][0]==-1)
        {
            area_state[t][0]==t;
        }
        else
        {
            for(int j=0; area_state[t][j]!=-1; ++j)
            {
                area_state[t][j+1]=area_state[t][j];
            }
            area_state[t][0]=t;
        }
    }

}
bool judge(int a,int b,int**area_state)
{
    bool flag=true;
    if(a==b)
    {
        flag=false;
    }
    int a1,a2,b1,b2;
    find(a,&a1,&a2,area_state);
    find(b,&b1,&b2,area_state);
    if(a1==b1)
    {
        flag=false;
    }
    return flag;
}
void move_onto(int a,int b,int**area_state)
{
    int a1,a2,b1,b2;
    if(judge(a,b,area_state)==false)
    {
        return;
    }
    resume(a,area_state);
    resume(b,area_state);
    find(a,&a1,&a2,area_state);
    find(b,&b1,&b2,area_state);
    area_state[b1][b2+1]==a;
    area_state[a1][a2]==-1;
}

void move_over(int a,int b,int**area_state)
{
    int a1,a2,b1,b2,i;
    if(judge(a,b,area_state)==false)
    {
        return;
    }
    resume(a,area_state);
    find(a,&a1,&a2,area_state);
    find(b,&b1,&b2,area_state);
    area_state[a1][a2]==-1;
    for( i=b2; area_state[b1][i]!=-1; ++i);
    area_state[b1][i]=a;
}
void pile_onto(int a,int b,int**area_state)
{
    int a1,a2,b1,b2,t;
    if(judge(a,b,area_state)==false)
    {
        return;
    }
    find(a,&a1,&a2,area_state);
    find(b,&b1,&b2,area_state);
    resume(b,area_state);
    for(int j=a2; area_state[a1][j]!=-1; ++j)
    {
        t=area_state[a1][j];
        area_state[a1][j]=-1;
        area_state[b1][b2+j+1-a2]=t;
    }


}
void pile_over(int a,int b,int**area_state)
{
    int a1,a2,b1,b2,i,t;
    if(judge(a,b,area_state)==false)
    {
        return;
    }

    find(a,&a1,&a2,area_state);
    find(b,&b1,&b2,area_state);
    for( i=b2; area_state[b1][i]!=-1; ++i);
    area_state[b1][i]=a;
    for(int j=a2+1; area_state[a1][j]!=-1; ++j)
    {
        t=area_state[a1][j];
        area_state[a1][j]=-1;
    while(-1)
        {++i;
        area_state[b1][i+1]=t;
        }
    }
}



int main()
{

    cout<<"ÇëÊäÈëÊýÁ¿"<<endl;
    cin>>n;
    char s1,s2;
    int a,b;
    int**area_state= new int*[n];
    for(int i = 0; i <n; i++)
    {
        area_state[i] = new int[n];
    }
    for(int i = 0; i <n; i++)
    {

        for(int j=0; j<n; ++j)
        {
            area_state[i][j]=-1;
        }
        area_state[i][0]=i;
    }
    while(-1)
    {
        cout<<"ÇëÊäÈë×Ö·û1"<<endl;
        cin>>s1;
        if(strcmp(s1,"quit")==0)
        {
            for(int i=0; i<n; ++i)
            {
                cout<<i<<":";
                for(int j=0; j<n; ++j)
                {
                    if(area_state[i]!=-1)
                    {
                        cout<<area_state[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
            break;

        }
        cout<<"ÇëÊäÈëa,×Ö·û2,b"<<endl;
        cin>>a>>s2>>b;
        if(strcmp(s1,"move")==0&&strcmp(s2,"onto")==0)
        {
            move_onto(a,b,area_state);
        }
        if(strcmp(s1,"move")==0&&strcmp(s2,"over")==0)
        {
            move_over(a,b,area_state);
        }
        if(strcmp(s1,"pile")==0&&strcmp(s2,"onto")==0)
        {
            pile_onto(a,b,area_state);
        }
        if(strcmp(s1,"pile")==0&&strcmp(s2,"over")==0)
        {
            pile_over(a,b,area_state);
        }
    }

    return 0;
}
