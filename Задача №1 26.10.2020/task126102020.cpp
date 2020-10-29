#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ofstream file;
    fstream text;
    text.open("text.txt");
    file.open("file.txt");
    int n;
    text>>n;
    int min1=1000;
    int min2=1000;
    int r=0;
    int map[n][2];
    for (int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                map[i][j]=0;
            }
        }

   // cout<<"n="<<n<<endl;
    int nach, koch;
    text>> nach>> koch;
    //cout<<"nach="<<nach<<endl;
    //cout<<"koch="<<koch<<endl;
    int mat[n][n];
        for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
           mat[i][j] = 0;
        }
    }
    for(int i=1;i<n;i++)
    {
        int j;
        text>>j;
       // cout<<"j="<<j<<endl;
        //mat[i][j-1]=1;
        mat[j-1][i]=1;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
           // cout<<mat[i][j]<<" ";
        }
       // cout<<endl;
    }
    if (mat[nach-1][koch-1]==1)
    {
        cout<<nach;
        return 0;
    }
    else
    {
        for (int z=1;z<n+1;z++)
        {
 const int inf=4000; // задаем бесконечность
    int start_position; // n-количество вершин,х используем для приема матрицы смежности
    start_position = z;
    start_position--; // в условии счет начинается с единицы, а в программе с нуля
    vector <int> verges [1001]; //задаем массив векторов, где i-ый вектор содержит в себе номера вершин в которые можно попасть с i-ой вершины
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (mat[i][j]==1){
                verges[i].push_back(j);
            }
        }
    }
    bool *used = new bool [n];
    for (int i=0; i<n; i++){
        used[i]=false;
    }
    int *distances = new int [n]; //задаем массив расстояний, где i-ый элемент - это расстояние от исходной вершины до  i-ой
    for (int i=0; i<n; i++){
        distances[i]=inf;
    }
    distances[start_position] = 0;
    for (int i=0; i<n; i++){ //ищем вершину с наименьшей длиной пути до заданной вершины
        int minimum=inf;
        int position = 0;
        for (int j=0; j<n; j++){
            if (distances[j]<minimum && !used[j]){
                minimum=distances[j];
                position=j;
            }
        }
        used[position]=true; //запоминаем, что применили алгоритм для вершины
        for (int i=0; i<verges[position].size(); i++){ // применяем алгоритм Дейкстры
            distances[verges[position][i]] = min(distances[verges[position][i]], (distances[position]+1));
        }
    }
   // for (int i=0; i<n; i++) {
        if((((distances[nach-1]==inf)?-1:distances[nach-1])!=0)&&(((distances[nach-1]==inf)?-1:distances[nach-1])!=-1))
        {
            map[z][0]=(distances[nach-1]==inf)?-1:distances[nach-1];
        }
        if((((distances[koch-1]==inf)?-1:distances[koch-1])!=0)&&(((distances[koch-1]==inf)?-1:distances[koch-1])!=-1))
        {
            map[z][1]=(distances[koch-1]==inf)?-1:distances[koch-1];
        }





   // }
   // cout<<endl;
        }
        for (int i=0;i<n;i++)
        {
            if ((map[i][0]!=0)&&map[i][1]!=0)
            {
                if ((min1>=map[i][0])&&(min2>=map[i][1]))
                {
                    min1 = map[i][0];
                    min2 = map[i][1];
                    r=i;
                }
            }
            //for(int j=0;j<2;j++)
            //{
                //cout<<map[i][j]<<" ";
            //}
            //cout<<endl;
        }
        file<<r;
        cout<< "Ответ смотрите в file"<<endl;
    text.close();
    file.close();
    return 0;
    }
}
