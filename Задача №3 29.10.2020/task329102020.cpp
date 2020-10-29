#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ofstream file;
    fstream text;
    text.open("text.txt");
    file.open("file.txt");
    char n;
    char m;
    text>>n;
    text>>m;
    int sum=0;
    while(n!=m)
    {
        sum++;
        n=m;
        text>>m;
    }
    file<<sum+1;
    cout<<"Ответ смотрите в file"<<endl;
    text.close();
    file.close();
    return 0;
}
