#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;

int n, v;
vector <vector <int> > M;
vector <int> visited;
vector <int> colours;
vector <int> cyclicnodes;
// рекурсивный поиск в глубину для каждой вершины, а так же помечаем каждую вершину одним из трех цветов
bool dfs (int v) {
    colours[v] = 2;
    visited[v]++;
    for (int i = 0; i < M[v].size(); i++) {
        if (colours[M[v][i]] != 3 and visited[M[v][i]] != 2) {
            if (colours[M[v][i]] == 1) {
                if (dfs(M[v][i])) return true;
            }
            else {
                if (colours[M[v][i]] == 2) return true;
            }
        }
    if (colours[v] == 3) return false;
    if (visited[v] == 2) return false;
    }
    colours[v] = 3;
    return false;
}
// поиск цикличных вершин
void cyclic (int v) {
    for (int i = 0; i < M[v].size(); i++) {
        cyclicnodes.push_back(M[v][i]);
        if (cyclicnodes[0] == cyclicnodes[cyclicnodes.size() - 1] and cyclicnodes.size() > 1)
            break;
        cyclic (M[v][i]);
    }
}

int main() {

    setlocale(LC_ALL, "rus");
    fstream text;
    text.open("text.txt");
    string buk;
    getline(text,buk);
    n = buk[0] - '0';
    //cout << "n = "<< n<< endl;
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
   v=0;
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        //cout<<mas[i][j]<<" ";

    }
    //cout<<endl;
}
//cout<<endl;
    M.resize(n);
    visited.resize(n);
    colours.resize(n);
    colours.assign(n, 1);
    visited.assign(n, 0);

    int o=0;
    for ( int i =0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (mas[i][j] == mas[j][i])
            {
                mas[j][i] =0;
            }
        }
    }
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
        //cout<<mas[i][j]<<" ";
        //if (mas[i][j]==1) v++;
    }
    //cout<<endl;
}
    for(int i =0 ; i<n;i++)
{
    for(int j =0;j<n;j++)

    {
      //  cout<<mas[i][j]<<" ";
        if (mas[i][j]==1) v++;
    }
   // cout<<endl;
}
//cout<< "v="<<v;
int v1[v];
    int v2[v];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            if( mas[i][j]==1)
        {
            v1[o]= i+1;
            v2 [o]= j+1;
            o++;
        }
    }
    for (int i=0;i<v;i++)
    {
        //cout<<v1[i]<<" "<<v2[i]<<endl;
    }
     o =0;
    for (int i = 0; i < v; i++) {

        M[v1[o] - 1].push_back(v2[o] - 1);
        o++;
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (dfs(i)) t = 1;
    }
    if (t == 0) cout << "NO";
    else {
    cout << "YES" << endl;
   /* vector <int> iscyclic;
    for (int i = 0; i < colours.size(); i++) {
        if (colours[i] == 2) iscyclic.push_back(i);
    }
    cyclic (iscyclic[0]);
    for (int i = 1; i < cyclicnodes.size(); i++)
        cout << cyclicnodes[i] + 1 << " ";*/
    }
    return 0;
}
