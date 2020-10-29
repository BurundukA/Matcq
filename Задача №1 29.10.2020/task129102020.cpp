#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");
    ofstream file;
    fstream text;
    text.open("text.txt");
    file.open("file.txt");
    int kol;
    text>>kol;
    //cout<<kol<<endl;
    string word;
    text>>word;
   // cout<<word<<endl;
    int sum = 0;
    for (int i=0;i<word.size()-1;i++)
    {
        for (int j=i+1;j<word.size();j++)
        {
            if (word[i]==word[j])
            {
                word[j]='0';
            }
        }
    }
    for (int i=0;i<word.size();i++)
    {
        if(word[i]!='0')
        {
            sum++;
        }
    }
   // cout<<sum<<endl;
    int otv=1;
    for (int i=0;i<kol;i++)
    {
        otv=otv*(sum);
        sum=sum-1;
    }
    //cout<<sum<<endl;
   // cout<<word;
    file<<otv;
    cout<<"Смотрите ответ в file"<<endl;
    text.close();
    file.close();
    return 0;
}
