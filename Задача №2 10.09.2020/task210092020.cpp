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
    int m = buk[2] -'0';
    cout << "m = "<< m <<endl;
    int mas[m][2];
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
    for(int i =0 ; i<m;i++)
{
    for(int j =0;j<2;j++)

    {
        cout<<mas[i][j]<<" ";
    }
    cout<<endl;
}
int st1[m];
int st2[m];

for ( int i=0;i<m;i++)
{
    st1[i]= mas [i][0]-1;
}
for ( int i=0;i<m;i++)
{
    st2[i]= mas [i][1]-1;
}
cout << "st1"<<endl;
for ( int i=0;i<m;i++)
{
    cout<<st1[i]<<" ";
}
cout<<endl;
cout<<"st2"<<endl;
for ( int i=0;i<m;i++)
{
    cout<<st2[i]<<" ";
}
int maq [n][n];
for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        maq[i][j]=0;
    }
}
for (int i=0 ;i<m;i++)
{
    maq [st1[i]][st2[i]]=1;
}
cout<<endl;
for(int i=0;i<n;i++){
{
    for(int j =0;j<n;j++)

    {
        cout<<maq[i][j]<<" ";
    }
    cout<<endl;
}
}
int l=0;
for(int i=0;i<n;i++){
{ cout<<(i+1)<<" ";
    for(int j =0;j<n;j++)
    {
        if (maq[i][j]==1)
        {
            cout<<(j+1)<<" ";
            l++;
        }
    }
    if (l==0)
    {
        cout<<l;
    }
    l=0;
    cout<<endl;
}
}
    return 0;
}
