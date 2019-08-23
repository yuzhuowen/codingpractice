#include <iostream>
#include<set>
#include <algorithm>
using namespace std;


int main()
{
    char schedule[5][4][4];
    int shared[16][16]= {0};
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            for(int k=0; k<4; ++k)
            {
                cin>>schedule[i][j][k];
            }
            for(int k=0; k<4; ++k)
            {
                for(int l=0; l<4; ++l)
                {
                    shared[schedule[i][j][k]-'A'][schedule[i][j][l]-'A']=1;
                    shared[schedule[i][j][l]-'A'][schedule[i][j][k]-'A']=1;
                }
            }
        }
    }
    bool flag=true;
    for(int day=3; flag&&day<5; ++day)
    {
        bool settled[16];
        for(int i=0; i<16; ++i)
        {
            settled[i]=false;
        }
        for(int table=0; flag&&table<3; ++table)
        {
            int a,b;
            set<int> sa, sb, si;
            set<int>::iterator itr;
            itr = si.begin();
            for(int i=0; i<16; ++i)
            {
                if(!settled[i])
                {
                    a=i;
                    break;
                }
            }
            for(int i=0; i<16; ++i)
            {
                if(i!=a&&!settled[i]&&shared[a][i]!=0)
                {
                    b=i;
                    break;
                }
            }
            for(int i=0; i<16; ++i)
            {
                if(i!=a&&!settled[i]&&shared[a][i]!=0)
                {
                    sa.insert(i);

                }
                if(i!=b&&!settled[i]&&shared[b][i]!=0)
                {
                    sb.insert(i);

                }
            }
            set_intersection(sa.begin(), sb.end(), sa.begin(),sa.end(),inserter(si, itr));
            if(si.size()==2)
            {itr=si.begin();
             int c=*(si.begin());
             ++itr;
             int d=*itr;
             settled[a]=settled[b]=settled[c]=true;
             schedule[day][table][0]=a+'A';
             schedule[day][table][1]=b+'A';
             schedule[day][table][2]=c+'A';
             schedule[day][table][3]=d+'A';
             shared[a][b]=shared[a][c]=shared[a][d]=shared[b][c]=shared[b][d]=shared[c][d]=1;
             shared[b][a]=shared[c][a]=shared[d][a]=shared[c][b]=shared[d][b]=shared[d][c]=1;
            }
            else
            {
                flag=false;
            }

            for(int p=0,m=0; flag&&p<16; ++p)
            {
                if(!settled[p]!=0)
                {
                    schedule[day][3][m++]=p+'A';
                }
            }




        }









    }


    if(flag)
    {
        for(int i=0; i<5; ++i)
        {
            for(int j=0; j<4; ++j)
            {
                for(int k=0; k<4; ++k)
                {
                    cout<<schedule[i][j][k];
                }
                cout<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"It is not possible to complete this schedule."<<endl;
    }
    return 0;
}
