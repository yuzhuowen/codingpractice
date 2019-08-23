#include <iostream>

using namespace std;
int main()
{
    int row,col,entry;
    while(1)
    {
        cin>>row>>col>>entry;
        if(row==0&&col==0&&entry==0)
        {
            break;
        }
        char **grid=new char*[row];
        for(int i=0; i<row; ++i)
        {
            grid[i]=new char[col];
            for(int j=0; j<col; ++j)
            {
                cin>>grid[i][j];
            }
        }
        int x=0,y=entry-1,k=0,record[1000][2],t;

        record[k][0]=0;
        record[k][1]=y;
        while(1)
        {
            switch(grid[x][y])
            {
            case 'N':
                --x;
                break;
            case 'S':
                ++x;
                break;
            case 'W':
                --y;//x,y要弄清楚
                break;
            case 'E':
                ++y;
                break;
            }
            ++k;
            record[k][0]=x;
            record[k][1]=y;
            //cout<<x<<" "<<y<<endl;
            if(x<0||y<0||x>row-1||y>col-1)//-1的问题
            {
                cout<<k<<" step(s) to exit"<<endl;
                break;
            }
            for(int i=k-2; i>=0; --i)
            {
                if(record[k][0]==record[i][0]&&record[k][1]==record[i][1])
                {
                    cout<<i<<" step(s) before a loop of "<<k-i<<" step(s)"<<endl;
                    t=1;
                    break;
                }
            }
            if(t==1)
            {
                break;
            }


        }



        for(int i=0; i<row; ++i)
        {
            delete []grid[i];
        }
        delete []grid;
    }

    return 0;
}
