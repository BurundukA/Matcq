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
    int mas[n*n][n*n];
    int y=0;
    int v = 0;
    int r = 0;
    while (!text.eof())
    {
        getline(text,buk);
        //cout<< buk<< endl;
        //cout<<buk.size()<<endl;
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

   // cout<<endl;
/*for(int i =0 ; i<n*n;i++)
{
    for(int j =0;j<n*n;j++)

    {
        cout<<mas[i][j]<<" ";
    }
    cout<<endl;
}*/


    int loh[10];
for (int i=0 ; i<n*n;i ++)
{
    for (int j=0 ;j<n*n; j++)
    {
        loh [j] = mas[i][j];

    }
    for (int h=0 ;h<(n*n-1);h++)
    {

        for (int w = h+1 ;w<(n*n);w++)
        {
            if(loh[h]==loh[w])
            {
                cout<<"Cудоку неправильное"<<endl;
                return 0;
            }
        }
    }
    //cout<<endl;
}


for (int i=0 ; i<n*n;i ++)
{
    for (int j=0 ;j<n*n; j++)
    {
        loh [j] = mas[j][i];

    }

    for (int h=0 ;h<(n*n-1);h++)
    {

        for (int w = h+1 ;w<(n*n);w++)
        {
            if(loh[h]==loh[w])
            {
                cout<<"Cудоку неправильное"<<endl;
                return 0;
            }
        }
    }
}
int p = 0;
int b = 0;
int q = 0;
int b1;
int p1;
q=0;
for(int i = 0; i<n; i++)
{
    for(int j = 0; j<n; j++)
    {
        for(int v = 0; v<n; v++)
        {
            for(int w = 0; w<n; w++)
            {
                loh[q] = mas[p][b];
                //cout<<loh[q]<<" ";
                b++;
                q++;
            }
            b1 = b;
            b=b-n;
        p ++;
        }
        q=0;
 for (int h=0 ;h<(n*n-1);h++)
    {

       for (int z = h+1 ;z<(n*n);z++)
        {
            if(loh[h]==loh[z])
            {
                cout<<"Cудоку неправильное"<<endl;
                return 0;
            }
        }
    }
//cout<<endl;

        b = b1;
        p = p - n;

    }


    p = p + n -1;
}
cout<<"Судоку правильное"<<endl;
    text.close();
    return 0;
}
