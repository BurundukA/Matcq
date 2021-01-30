#include <iostream>

using namespace std;

int main()
{
    int h=0;
    int min =9;
    int sum =0;
    int kol =0;
    int p;
    long long int sr=0;
    for ( int i=2020;i<=647038;i++)
    {
        if (i<10000)
        {
        int *mas = new int [4];
        p=i;
    while (p>0)
    {
        mas[h] = p%10;
        if (mas[h]<=min)
        {
            min = mas[h];
        }
        sum = sum + mas[h];
        h++;
        p= p/10;
    }
    //cout <<min<<endl;
    //cout <<sum<<endl;
    if (sum <10)
    {
    if ((min!=mas[3]) and (min!=mas[2]) and (min!=mas[1]))
    {
        kol++;
        sr = sr +i;
    }
    }
    sum =0;
    h=0;
    min =9;
    }
    if ((i>9999)and (i<100000))
    {
         int *mas = new int [5];
        p=i;
    while (p>0)
    {
        mas[h] = p%10;
        if (mas[h]<=min)
        {
            min = mas[h];
        }
        sum = sum + mas[h];
        h++;
        p= p/10;
    }
    //cout <<min<<endl;
    //cout <<sum<<endl;
    if (sum <10)
    {
    if ((min!=mas[4]) and (min!=mas[3]) and (min!=mas[2]))
    {
        kol++;
        sr = sr +i;
    }
    }
    sum =0;
    h=0;
    min =9;
    }
    if (i>99999)
    {
         int *mas = new int [6];
        p=i;
    while (p>0)
    {
        mas[h] = p%10;
        if (mas[h]<=min)
        {
            min = mas[h];
        }
        sum = sum + mas[h];
        h++;
        p= p/10;
    }
    //cout <<min<<endl;
    //cout <<sum<<endl;
    if (sum <10)
    {
    if ((min!=mas[5]) and (min!=mas[4]) and (min!=mas[3]))
    {
        kol++;
        sr = sr +i;
    }
    }
    sum =0;
    h=0;
    min =9;
    }
    }
    cout <<kol<<endl;
    cout <<sr<<endl;
    return 0;
}
