#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
     setlocale(LC_ALL, "rus");
    fstream text;
    text.open("text.txt");
    string buk;
    getline(text,buk);
    int n = buk[0] - '0';
    cout << "n = "<< n<< endl;
    int mas[n][n];
    int y=0;
    int v = 0;
    int r = 0;
    while (!text.eof())
    {
        getline(text,buk);
         for (int i=0;i<buk.size()-1; i++)
        {
            if(buk[i]!=' ')
            {
                if(buk[i+1]!=' ')
                {
                    mas[v][r] = (buk[i] - '0')*10+(buk[i+1] - '0');
                r++;
                i++;
                }
               else
                    {
                        mas[v][r] = buk[i] - '0';
                r++;

                    }

            }


        }

        v++;
        r=0;
    }
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        cout<<mas[i][j]<<" ";
    }
    cout<<endl;
}
int m=0;
cout << n <<" ";
for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        if (mas[i][j]==1)
        {
            m++;
        }
    }
}
cout<<m<<endl;
for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        if (mas[i][j]==1)
        {
            cout << (i+1) <<(j+1)<<endl;
        }
    }
}
    return 0;
}
