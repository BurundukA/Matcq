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
    int y=0;
    int v = 0;
    int r = 0;
    int mas[n][n];
    int st=0;
    for(int i=0;i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        mas[i][j]=0;
    }
}
    while (!text.eof())
    {
        getline(text,buk);
         int kol = buk[0]- '0';
         cout<<"kol="<<kol<<endl;
         int gop[kol];
        int pol=0;
         for (int i=2;i<buk.size()-1; i++)
        {
            if(buk[i]!=' ')
            {
                if(buk[i+1]!=' ')
                {
                    gop[pol] = (buk[i] - '0')*10+(buk[i+1] - '0');
                pol++;
                i++;
                }
               else
                    {
                        gop[pol] = buk[i] - '0';
                pol++;

                    }

            }


        }
        for (int r=0;r<kol;r++)
        {
            cout<<gop[r]<<" ";
        }
        for (int r=0;r<kol;r++)
        {
            mas[st][gop[r]-1]=1;
        }
        st++;
    }
cout<<endl;
    for(int i=0;i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        cout<<mas[i][j]<<" ";
    }
    cout<<endl;
}

    return 0;
}
