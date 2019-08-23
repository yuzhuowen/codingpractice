#include <iostream>

using namespace std;

int main()
{
    int k,a,b,m,n,name,repeat;
    char diretion,action;
    for(; k>0; --k)
    {
        cin>>a>>b;
        int **size=new int*[b];
        bool flag=true;
        for (int i=0; i<b; ++i)
        {
            size[i]=new int[a];
        }
        cin>>n>>m;
        int **robot=new int*[n];
        for (int i=0; i<n; ++i)
        {
            robot[i]=new int[3];
        }
        for (int i=0; i<n; ++i)
        {
            cin>>robot[i][0]>>robot[i][1]>>diretion;
            robot[i][2]=diretion-'A';
        }
        for(int i=0; i<m; ++i)
        {
            cin>>name>>action>>repeat;
            for(int j=0; j<repeat; ++j)
            {
                switch(action)

                {
                case 'L':
                    switch(robot[name][2])
                    {
                    case 5:
                        robot[name][2]=13;
                        break;
                    case 13:
                        robot[name][2]=22;
                        break;
                    case 22:
                        robot[name][2]=18;
                        break;
                    case 18:
                        robot[name][2]=5;
                        break;
                    }
                    break;
                case 'R':
                    switch(robot[name][2])
                    {
                    case 5:
                        robot[name][2]=18;
                        break;
                    case 13:
                        robot[name][2]=5;
                        break;
                    case 22:
                        robot[name][2]=13;
                        break;
                    case 18:
                        robot[name][2]=22;
                        break;
                    }
                    break;
                case 'F':
                    switch(robot[name][2])
                    {
                    case 5:
                        ++robot[name][1];
                        break;
                    case 13:
                        ++robot[name][0];
                        break;
                    case 22:
                        --robot[name][1];
                        break;
                    case 18:
                        --robot[name][0];
                        break;
                    }
                    break;

                }
                if(robot[name][0]<0||robot[name][1]<0||robot[name][0]>3||robot[name][1]>3)
                {
                    cout<<"Robot"<<name<<"crashes into the wall"<<endl;
                    flag=false;
                    break;
                }
                for(int i=0; i<n; ++i)
                {
                    if(robot[name][0]==robot[i][0]&&robot[name][0]==robot[i][0]&&name!=i)
                    {
                        cout<<"Robot"<<name<<"crashes into robot"<<i<<endl;
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                {
                    break;
                }
            }
            if(!flag)
            {
                break;
            }
        }
        if(flag)
        {
            cout<<"OK"<<endl;
        }
        for(int i=0; i<b; ++i)

        {
            delete []size[i];
        }

        delete []size;
    }
    return 0;
}
