#include <iostream>
#include <fstream>

using namespace std;

int i,j,k;
char a[10][10];
int U(int i,int j)
{
    char c;
    c=a[i][j];
    a[i][j] = ' ';
    if ((c=='W')&&(a[i+1][j]=='B')){U(i+1,j);}
    if ((c=='B')&&(a[i+1][j]=='W')){U(i+1,j);}
    if ((c=='W')&&(a[i-1][j]=='B')){U(i-1,j);}
    if ((c=='B')&&(a[i-1][j]=='W')){U(i-1,j);}
    if ((c=='W')&&(a[i][j+1]=='B')){U(i,j+1);}
    if ((c=='B')&&(a[i][j+1]=='W')){U(i,j+1);}
    if ((c=='W')&&(a[i][j-1]=='B')){U(i,j-1);}
    if ((c=='B')&&(a[i][j-1]=='W')){U(i,j-1);}
}

int main()
{
    setlocale(LC_ALL, "rus");
    fstream text;
    ofstream file;
    file.open("file.txt");
    text.open("text.txt");
    for (int i=1;i<9;i++)
    {
        for (int j=1;j<9;j++)
        {
            text>>a[i][j];
        }
    }
    for (int i=1;i<9;i++)
    {
        a[0][i]= ' ';
        a[9][i]= ' ';
        a[i][0]= ' ';
        a[i][9]= ' ';
    }
    k=0;
    for (int i=1;i<9;i++)
    {
        for (int j=1;j<9;j++)
        {
            if(a[i][j]!=' ')
            {
                k= k+1;
                U(i,j);
            }
        }
    }
    file<<k;
    cout<< "Ответ смотрите в file"<<endl;
    text.close();
    file.close();
    return 0;
}
