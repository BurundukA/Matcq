#include <iostream>

using namespace std;

int main()
{
    int p=0;
    int h=0;
    int d=0;
    int del =0;
    int a=0;
    int kol=0;
    int sum=0;
    for ( int i=9999;i<=99999;i++)
    {
        if (i<10000)
        {
        int *mas = new int [4];
        p=i;
    while (p>0)
    {
        mas[h] = p%10;
        sum = sum + mas[h];
        h++;
        p= p/10;
    }
    if (i%sum==0)
    {
        kol++;
        a=i;
    }
    sum =0;
    h=0;
        }
        if (i<100000)
        {
        int *mas = new int [5];
        p=i;
    while (p>0)
    {
        mas[h] = p%10;
        sum = sum + mas[h];
        h++;
        p= p/10;
    }
    if (i%sum==0)
    {
        kol++;
        a=i;
    }
    sum =0;
    h=0;
        }
    }
    cout <<kol<<endl;
    cout<<a<<endl;
    return 0;
}
