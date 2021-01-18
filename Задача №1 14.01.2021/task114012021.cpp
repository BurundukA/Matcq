#include <iostream>

using namespace std;

int main()
{
   int n,i,j;
   int d2[5];
   for ( int i=110203;i<=110245;i++)
   {
       n=0;
       for (j=1;j<=i;j++)
       {
           if ((i%j==0)and(j%2==0))
           {
               n= n+1;
               if(n>4) break;
               d2[n] = j;
           }
       }
       if (n==4)
       {
           cout <<d2[1] <<" " <<d2[2] << " " <<d2[3] <<" " <<d2[4]<<endl;
       }
   }
    return 0;
}
