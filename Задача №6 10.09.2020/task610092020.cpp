#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
int main() {
     setlocale(LC_ALL, "rus");
    fstream text;
    ofstream file;
    file.open("output.txt");
    text.open("text.txt");
    string buk;
    getline(text,buk);
    int n = buk[0] - '0';
    //cout << "n = "<< n<< endl;
    getline(text,buk);
    int x1 = buk[0] - '0';
    int y1 = buk[2] - '0';
   // cout << "x1 = "<< x1<< endl;
   // cout << "y1 = "<< y1<< endl;
    getline(text,buk);
    int x2 = buk[0] - '0';
    int y2 = buk[2] - '0';
   // cout << "x2 = "<< x2<< endl;
    //cout << "y2 = "<<y2<< endl;
int i,j,k,u,v;queue<pair<int,int> >q;
int x[8]={-2,-2,-1,-1,1,1,2,2},
y[8]={-1,1,-2,2,-2,2,-1,1};
int d[n+1][n+1];
for(i=0;i<=n;++i)
for(j=0;j<=n;++j)d[i][j]=1000000000;
d[x1][y1]=0; q.push(make_pair(x1,y1));
while(!q.empty()){
i=q.front().first;j=q.front().second;q.pop();
for(k=0;k<8;++k){u=i+x[k];v=j+y[k];
if(u>0&&u<=n&&v>0&&v<=n&&d[u][v]>d[i][j]+1){
d[u][v]=d[i][j]+1;q.push(make_pair(u,v));}}}
//cout<<d[x2][y2];
file<<d[x2][y2];
cout<<"Ответ смотрите в файле output"<<endl;
text.close();
file.close();
 return 0;}

