#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <fstream>

using namespace std;
#define INF 10000000000
#define MAX 100000
vector <pair <int, long long> > G[MAX];
vector <int> path;
vector <int> ans;
set <pair <long long, int> > q;
long long length[MAX];
int parent[MAX];

int main()
{
     setlocale(LC_ALL, "rus");
    fstream text;
    text.open("text.txt");
    string buk;
    getline(text,buk);
    int raz;
    raz = buk[0] - '0';
    //cout << "raz = "<< raz<< endl;
    int ot;
    int lo;
    ot = buk[2] - '0';
    lo = buk[4] - '0';
   // cout<< ot <<" "<<lo<<endl;
    int mas[raz][raz];
    int y=0;
    int f = 0;
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
                    mas[f][r] = (buk[i] - '0')*10+(buk[i+1] - '0');
                r++;
                i++;
                }
               else
                    {
                        mas[f][r] = buk[i] - '0';
                r++;

                    }

            }


        }

        f++;
        r=0;
    }
   f=0;
   int kol = 0;
   for(int i =0 ; i<raz;i++)
{
    for(int j =0;j<raz;j++)

    {
       // cout<<mas[i][j]<<" ";
        if (mas[i][j]!=0)
        {
            kol++;


        }

    }
 //   cout<<endl;
}
   int froms[kol];
   int tos[kol];
   int lengs [kol];
   int h=0;
    for(int i =0 ; i<raz;i++)
{
    for(int j =0;j<raz;j++)

    {
        //cout<<mas[i][j]<<" ";
        if (mas[i][j]!=0)
        {

            froms[h]= i;
            tos[h] = j;
            lengs[h] = mas[i][j];
            h++;

        }

    }
   // cout<<endl;
}
//cout<<"kol="<<kol;
for (int i=0;i<kol;i++)
{
   // cout<< froms[i] << " " << tos[i] << " " << lengs[i]<< " "<<endl;
}
    ios :: sync_with_stdio(false);
    int n,m,a,b;
    n = raz;
    m = kol;
    a = ot;
    b = lo;
    a--;
    b--;
    for (int i=0;i<m;i++)
    {
        int from, to, len;
        from = froms[i];
        to = tos[i];
        len = lengs[i];
        //cout<<len;

        G[to].push_back(make_pair(from, len));
        G[from].push_back(make_pair(to,len));
    }
    for ( int i=0;i<n;i++) length[i]=INF;
    length[a] = 0;
    q.insert(make_pair(length[a],a));
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int i=0;i<G[v].size();i++)
        {
            int to = G[v][i].first, len = G[v][i].second;
            if (length[v] + len < length[to])
            {
                q.erase(make_pair(length[to],to));
                length[to] = length[v] + len;
                parent[to] = v;
                q.insert(make_pair(length[to],to));
            }
        }
    }
    if(length[b]==INF)
    {
        cout<<"No way"<<endl;
        return 0;
    }
    cout<<length[b]<<endl;
    int c=b;
    while(c!=a)
    {
        ans.push_back(c+1);
        c = parent[c];
    }
    ans.push_back(a+1);
    cout<<ans[ans.size()-1];
    for (int it = ans.size()-2;it>=0;it--) cout<<" "<<ans[it];
    cout<<endl;
    return 0;
}
