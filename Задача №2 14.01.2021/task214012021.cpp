#include <iostream>

using namespace std;

int main()
{
    int n,m,d;
    n = 48;
    d = 0;
    for ( int i=84052;i<=84130;i++)
    {
        m=0;
        for ( int j=1;j<=i;j++)
        {
            if (i%j==0)
            {
                m ++;
            }
        }
        if (m>d)
        {
            d = m;
            n = i;
        }
    }
    cout <<d<<" "<<n;
    return 0;
}
