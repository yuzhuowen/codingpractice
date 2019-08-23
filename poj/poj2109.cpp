#include <iostream>
#include<cmath>
using namespace std;

int main()
{int n,k,p;
    while(n!=0&&p!=0)
    {

        cin>>n>>p;
        double logn=log(n*1.0),logp=log(p*1.0);
        k=(int)(logp/logn+0.5);
        cout<<k<<endl;
    }

    return 0;
}
