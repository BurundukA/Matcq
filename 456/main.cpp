#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream file;
    file.open("27-A.txt");
    int N;
    file >>N;
    int a;
    int b;
    int sum = 0;
    int maxch = 0;
    int maxnch = 0;
    int minraz =0;
     int sumch =0;
     int kolch =0;
     int kolnch =0;
    for (int i=0;i<N;i++)
    {
        file >>a >>b;
        if(a>=b)
        {
            sum = sum + a;
            if ((a%2==0)and(b%2==0))
            {
                kolch++;
            }
            if ((a%2!=0)and(b%2!=0))
            {
                kolnch++;
            }
            if ((a%2==0)and(b%2!=0))
            {
                kolch++;
                    if((-a+b)>=minraz)
                       {
                           minraz=-a+b;
                           maxch = a;
                       }
            }
            if ((a%2!=0)and(b%2==0))
            {
                kolnch++;
                    if((-a+b)>=minraz)
                       {
                           minraz=-a+b;
                           maxnch = a;
                       }

            }
             if(a<=b)
        {
            sum = sum + b;
            if ((b%2==0)and(a%2==0))
            {
                kolch++;
            }
            if ((b%2!=0)and(a%2!=0))
            {
                kolnch++;
            }
            if ((b%2==0)and(a%2!=0))
            {
                kolch++;
                    if((-b+a)>=minraz)
                       {
                           minraz=-b+a;
                           maxch = b;
                       }
            }
            if ((b%2!=0)and(a%2==0))
            {
                kolnch++;
                    if((-b+a)>=minraz)
                       {
                           minraz=-b+a;
                           maxnch = b;
                       }
            }
            }
        }
    }
        sumch=sum%2;
    //    cout<<sum<<endl<<kolch<<endl<<kolnch<<endl<<minraz<<endl;
    if((sumch==0)and(kolch>=kolnch))
    {
        cout<<sum<<endl;
    }
     if((sumch!=0)and(kolch<=kolnch))
    {
        cout<<sum<<endl;
    }
    if((sumch==0)and(kolch<=kolnch))
    {
        cout<<sum+minraz<<endl;
    }
     if((sumch!=0)and(kolch>=kolnch))
    {
        cout<<sum+minraz<<endl;
    }
    return 0;
}

