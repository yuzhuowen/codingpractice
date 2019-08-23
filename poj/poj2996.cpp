#include <iostream>

using namespace std;

int main()
{
    char chessbroad[17][33];
    char white[15][3],black[15][3];
    white[0][0]=black[0][0]='K';
    white[1][0]=black[1][0]='Q';
    white[2][0]=black[2][0]='R';
    white[3][0]=black[3][0]='R';
    white[4][0]=black[4][0]=white[5][0]='B';
    white[6][0]=black[6][0]=black[5][0]='N';
    for(int i=7; i<=14; ++i)
    {
        white[i][0]=black[i][0]='P';
    }
    for(int i=0; i<15; ++i)
    {
        white[i][1]=white[i][2]=black[i][1]=black[i][2]='0';
    }
    for(int i=0; i<17; ++i)
    {
        for(int j=0; j<33; ++j)
        {
            cin>>chessbroad[i][j];
        }
    }
    for(int i=15; i>=9; i-=2)
    {
        for(int j=2; j<=30; j+=4)
        {
            if(chessbroad[i][j]==':'&&chessbroad[i][j]=='.')
            {
                continue;
            }
            for(int k=0; k<15; ++k)
            {
                if(chessbroad[i][j]==white[k][0]&&white[k][1]=='0')
                {
                    white[k][2]=8-i/2+'0';
                    white[k][1]=j/4+'a';
                    break;
                }
            }

        }
    }
    for( int i=1; i<=7; i+=2)
    {
        for(int j=2; j<=30; j+=4)
        {
            if(chessbroad[i][j]==':'&&chessbroad[i][j]=='.')
            {
                continue;
            }
            for(int k=0; k<15; ++k)
            {
                if(chessbroad[i][j]==black[k][0]-'A'+'a'&&black[k][1]=='0')
                {
                    black[k][2]=8-i/2+'0';
                    black[k][1]=j/4+'a';
                    break;
                }
            }

        }
    }
    cout<<"White:";
    for(int i=0; i<15; ++i)
    {
        if(i!=0)
        {
            cout<<",";
        }
        if(white[i][0]!='P')
        {
            cout<<white[i][0];
        }
        cout<<white[i][1]<<white[i][2];
    }
    cout<<endl;
    cout<<"Black:";
    for(int i=0; i<15; ++i)
    {
        if(i!=0)
        {
            cout<<",";
        }
        if(black[i][0]!='P')
        {
            cout<<black[i][0];
        }
        cout<<black[i][1]<<black[i][2];
    }
    return 0;
}
