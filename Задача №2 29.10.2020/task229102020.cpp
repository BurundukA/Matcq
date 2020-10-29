#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    fstream text;
    ofstream file;
    text.open("text.txt");
    file.open("file.txt");
    int kols;
    text>>kols;
    int kolb;
    text>>kolb;
    int otv = kolb;
    for (int i=1;i<kols;i++)
    {
        otv= otv*(kolb-1);
    }
    file<<otv;
    cout<<"Ответ смотрите в file"<<endl;
    text.close();
    file.close();
    return 0;
}
