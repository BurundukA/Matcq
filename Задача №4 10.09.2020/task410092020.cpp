#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
     setlocale(LC_ALL, "rus");
    fstream text;
    text.open("text.txt");
    ofstream file;
    file.open("output.txt");
    string buk;
    getline(text,buk);
    int n = buk[0] - '0';
   // cout << "n = "<< n<< endl;
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
    for (int i=0;i<n;i++)
    {
        if (mas[i][i]==1)
        {
           // cout<<"NO"<<endl;
           cout<<"Ñלמענטעו פאיכ output"<<endl;
           file<<"NO"<<endl;
            return 0;
        }
        else
        {
            mas[i][i]=0;
        }
    }
    int kol =0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
                if(mas[i][j]==1)
                {
                    kol++;
                }

    }
    }
   // cout<<"kol="<<kol<<endl;
    int same =0;
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        if ((mas[i][j]==mas[j][i])&&(mas[i][j]==1)&&(mas[j][i]==1))
        {
            same++;
        }
    }
}
if(same==kol)
{
    //cout<<"NO"<<endl;
    cout<<"Ñלמענטעו פאיכ output"<<endl;
    file<<"NO"<<endl;
    return 0;
}
//cout<<"YES"<<endl;
cout<<"Ñלמענטעו פאיכ output"<<endl;
file<<"YES"<<endl;
text.close();
file.close();
    return 0;
}
