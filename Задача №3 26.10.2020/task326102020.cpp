#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
#include <math.h>


using namespace std;
#define INF 1000000000000
#define MAX 100000

vector <pair <int, long long> > G[MAX];
vector <int> path;
vector <int> ans;
set <pair <long long, int> > q;
float length[MAX];
int parent[MAX];


int main()
{
    setlocale(LC_ALL, "rus");
    ios::sync_with_stdio(false);
    fstream text;
    ofstream file;
    file.open("file.txt");
    text.open("text.txt");
    int n;
    text>>n;
    int m;
    text>>m;
    int a;
    text>>a;
    a--;
    int b;
    text>>b;
     b--;

    float sum=0;

     for (int i=0; i<m; i++) {
        int from, to, len;
        text>>from;
        text>>to;
        text>>len;
        sum = sum +len;
        from--, to--;
        G[to].push_back(make_pair(from, len));
        G[from].push_back(make_pair (to, len));
    }
    for (int i=0; i<n; i++) length[i]=INF;
    length[a]=0;
    q.insert (make_pair (length[a], a));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());
        for (int i=0; i<G[v].size(); i++) {
            int to=G[v][i].first, len=G[v][i].second;
            if (length[v]+len<length[to]) {
                   q.erase (make_pair (length[to], to));
                   length[to]=length[v]+len;
                   parent[to]=v;
                   q.insert (make_pair (length[to], to));
            }
        }
    }
    if (length[b]==INF) { // если последняя вершина оказалась бесконечностью, значит, мы её не достигли
      //  cout << "-1";
        return 0;
    }
   // cout << length[b] << endl;

    sum = sum/100;
    sum  = (length[b]/100)*sum;
    cout.setf(ios::fixed);  // вывод в фиксированном формате
    cout.precision(2);      // вывод до 6 знака после точки, включительно
    file<< sum;
    cout<< "Ответ смотрите в file"<<endl;
    text.close();
    file.close();
    return 0;
}
